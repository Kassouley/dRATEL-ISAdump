require("string_ext")
local lfs = require("lfs")

local csv_parser = {}

function csv_parser.get_instruction_table(csv_path)
    local file = lfs.open_file(csv_path, "r")

    local instruction_table = {}
    file:read()
    for line in file:lines() do
        local values = line:split(",")
	local group = values[1]
	local opcode = tonumber(values[3])
	local instruction_name = values[4]
	local encoding_string = values[2]
	local operands = {}
	local modifiers = {}
	for i=5, 9 do
		if values[i] and values[i] ~= "" then 
			table.insert(operands, values[i])
		end
	end
	for i=10, #values do
		if values[i] and values[i] ~= "" then 
			table.insert(modifiers, values[i])
		end
	end
	if not instruction_table[group] then 
		instruction_table[group] = {} 
	end
	if opcode then
		if instruction_table[group][opcode] then
			print("Warning : Opcode '"..opcode.."' already exist for group '"..group.."'")
		end
		instruction_table[group][opcode] = {
	    		instruction_name = instruction_name,
			encoding_string = encoding_string,
			operands = operands,
			modifiers = modifiers
		}
	end
    end

    file:close()
    return instruction_table
end

function csv_parser.get_encoding_table(csv_path)
	local function parse_range(range_str)
    		local end_bit = range_str:match("%[(%d+)")
    		local start_bit = range_str:match("(%d+)%]")
    		if not start_bit or not end_bit then 
			error("No bit range found in encoding CSV.")
			return nil 
		end
    		return {tonumber(start_bit), tonumber(end_bit)}
	end

    	local encoding_table = {}
    	local field_indices = {}

    	local file = lfs.open_file(csv_path, "r")
	local header = file:read():split(",") 
        for i = 5, #header, 2 do
            table.insert(field_indices, {field = i, bits = i + 1})
        end
	for line in file:lines() do
            local col = line:split(",")
            if col then
		local name = col[1]
                local entry = {
		    name = name,
                    size = col[2],
		    encoding = col[3],
                    encoding_string = col[4],
                    fields = {}
                }

                for _, idx in ipairs(field_indices) do
                    local field_name = col[idx.field]
                    local bits_range = col[idx.bits]
		    if field_name and field_name ~= "" and bits_range and bits_range ~= "" then
                        local range = parse_range(bits_range)
                        if range then
				table.insert(entry.fields, {name = field_name, range = range})
                        end
                    end
                end
            	encoding_table[name] = entry
            end
        end

        file:close()
        return encoding_table
end

return csv_parser
