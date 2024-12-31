import csv

csv_file = "instructions.csv"

def parse_csv(csv_file, callback):
    # Read CSV and generate functions
    with open(csv_file, "r") as file:
        reader = csv.DictReader(file)
        functions = []
        for row in reader:
            if row["FORMAT"] != "MIMG":
                function_name, parameters, inputs, outputs, op_line, mod = get_data(row)
                functions.append(callback(function_name, parameters, inputs, outputs, op_line, mod))
    return functions

def get_operands(row):
    operands = []
    for i in range(5):
        operand_key = f"OPERAND{i}"
        if row[operand_key]:
            split_row = row[operand_key].split(":")
            op_name = split_row[1]
            op_type = split_row[3] if split_row[3] != "fx" else "f32"
            op_reg = split_row[5]
            is_src = True if split_row[2] == "SRC" else False
            operands.append({"name": op_name, "type": op_type, "reg": op_reg, "is_src": is_src})
    return operands

# Helper function to generate inline assembly template
def get_data(row):
    function_name = row["INSTRUCTIONS"].lower()
    operands = get_operands(row)
    parameters = []
    inputs = []
    outputs = []
    i = 0
    op_line = []
    for op in operands:
        op_name = op['name']
        op_type = op['type']
        op_reg = None
        op_arg = f"%{i}"
        param_decl = f"{op_type} {op_name}"

        # Handle special cases for 'op_arg' and 'op_decl'
        if function_name.startswith("scratch") and op_name == "saddr":
            op_arg = "off"
            param_decl = None
            op_reg = None
        elif function_name == "v_writelane_b32" and op_name == "ssrc1":
            op_arg = "m0"
            param_decl = None
            op_reg = None
        elif op_type == "b0" or op['reg'] == "VCC":
            op_arg = "off"
            param_decl = None
            op_reg = None
            if op['reg'] == "VCC":
                op_arg = "vcc"
        elif op_name == "hwreg":
            op_arg = "hwreg(1, 2, 4)"
            param_decl = None
            op_reg = None

        # Handle 'op_reg' based on 'reg' and 'name'
        elif op['reg'] in {"SV", "V"}:
            op_reg = f"\"v\"({op_name})"
        elif op['reg'] == 'I':
            op_reg = "\"i\"(0)"
            param_decl = None
        elif op['reg'] == "A":
            op_reg = f"\"a\"({op_name})"
        else:
            op_reg = f"\"s\"({op_name})"

        # Categorize into inputs or outputs
        if op["is_src"] and op_reg:
            inputs.append(op_reg)
        elif op_reg:
            outputs.append(op_reg.replace('"', '"=', 1))

        # Append valid declarations and arguments
        if param_decl:
            parameters.append(param_decl)
        op_line.append(op_arg)

        # Increment index if no special case altered it
        if param_decl or op_arg == f"%{i}":
            i += 1
    
    mod = ""
    if function_name.startswith("ds_gws"):
        mod = "gds"
    elif function_name == "buffer_store_lds_dword":
        mod = "lds"
    elif "_atomic_" in function_name:
        mod = "glc"
    elif function_name.endswith("_dpp"):
        mod = "row_newbcast:1"

    return function_name, parameters, inputs, outputs, op_line, mod

def get_function_code(function_name, parameters, inputs, outputs, op_line, mod):
    parameters_str = "; ".join(parameters)
    inputs_str = ", ".join(inputs)
    outputs_str = ", ".join(outputs)
    op_line_str = ", ".join(op_line)

    # Generate the inline assembly function
    function_code = f"""
__global__ void {function_name}() {{
    {parameters_str};
    __asm__ volatile("{function_name} {op_line_str} {mod}\\n" : {outputs_str} : {inputs_str});
}}
"""
    return function_code

def get_function_code_with_param(function_name, parameters, inputs, outputs, op_line, mod):
    parameters_str = ", ".join(parameters)
    inputs_str = ", ".join(inputs)
    outputs_str = ", ".join(outputs)
    op_line_str = ", ".join(op_line)

    # Generate the inline assembly function
    function_code = f"""
__global__ void {function_name}({parameters_str}) {{
    __asm__ volatile("{function_name} {op_line_str} {mod}\\n" : {outputs_str} : {inputs_str});
}}
"""
    return function_code


# Read CSV, generate functions, and write to output file
functions = parse_csv(csv_file, get_function_code)
output_file = "gpu_functions.cpp"
with open(output_file, "w") as f:
    f.write("#include <stdint.h>\n")  # Add necessary includes
    f.write("#include <hip/hip_runtime.h>\n")
    f.write("#include \"types.h\"\n\n")
    f.write("int main(void) { return 0; }\n\n")
    f.writelines(functions)

print(f"Generated {output_file} containing {len(functions)} functions.")

