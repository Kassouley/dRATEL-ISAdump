import re
import subprocess
import csv

def demangle_function(mangled_name):
    """
    Demangles a mangled function name using `c++filt` and extracts only the function name.
    :param mangled_name: The mangled function name to demangle.
    :return: The demangled function name as a string (only the function name).
    """
    try:
        result = subprocess.run(['c++filt', mangled_name], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        demangled_name = result.stdout.strip()
        # Extract only the function name using regex
        function_name_match = re.search(r"(\w+)(?=\()", demangled_name)  # Matches the function name before '('
        return function_name_match.group(1) if function_name_match else demangled_name
    except FileNotFoundError:
        raise RuntimeError("The `c++filt` command is not available. Please install it.")

def find_matches_and_next_occurrences(file_path):
    """
    Processes a file to extract content from `<.*>`, demangle it, and find its next occurrence.
    Additionally extracts the encoding from the next occurrence line.
    :param file_path: Path to the file to process.
    :return: A list of dictionaries containing the match and its next occurrence line with encoding.
    """
    matches = []
    pattern = re.compile(r"<(.*?)>:")  # Regex to extract content inside angle brackets
    encoding_pattern = re.compile(r":\s*([0-9A-Fa-f\s]+)\s*(<.*>)?$")  # Regex to capture encoding after ":"
    with open(file_path, 'r') as file:
        lines = file.readlines()[2:]

    for idx, line in enumerate(lines):
        match = pattern.search(line)
        if match:
            mangled_function = match.group(1)  # Extract content inside <>
            demangled_function = demangle_function(mangled_function)
            
            # Search for the next occurrence of the demangled function
            next_occurrence_line = None
            encoding = None
            for subsequent_line in lines[idx + 1:]:
                if demangled_function in subsequent_line:
                    next_occurrence_line = subsequent_line.strip()
                    # Extract the encoding after the ":" in the line
                    encoding_match = encoding_pattern.search(next_occurrence_line)
                    if encoding_match:
                        encoding = encoding_match.group(1).strip()
                    break
            
            matches.append({
                'line': line.strip(),
                'mangled_function': mangled_function,
                'demangled_function': demangled_function,
                'next_occurrence': next_occurrence_line,
                'encoding': encoding
            })

    return matches


# Example usage
output_csv = "test.csv"
file_path = "test.s"  # Replace with your file path
result = find_matches_and_next_occurrences(file_path)

# Output the results
with open(output_csv, mode='w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['Function Name', 'Encoding'])
    for match in result:
        print("Original Line:", match['line'])
        print("Mangled Function:", match['mangled_function'])
        print("Demangled Function (Function Name):", match['demangled_function'])
        print("Next Occurrence Line:", match['next_occurrence'])
        print("Encoding:", match['encoding'])
        print("-" * 40)
        csv_writer.writerow([match['demangled_function'], match['encoding']])

