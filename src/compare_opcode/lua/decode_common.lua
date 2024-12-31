local decode_common  = {}

local function reverse_range(range)
    local start_bit, end_bit = range[1], range[2]
    local reversed_start = 31 - end_bit
    local reversed_end = 31 - start_bit
    return reversed_start, reversed_end
end

function decode_common.decode_inst_group(binary_str, sorted_encoding_table)
    for _, entry in ipairs(sorted_encoding_table) do
        if binary_str:sub(1, #entry.encoding) == entry.encoding then
		return entry 
        end
    end
    error("No group found")
    return nil
end

function decode_common.decode_fields_from_group(binary_str, group)
        local fields = {}

        if group.fields then
                for _, field in ipairs(group.fields) do
                    	local name = field.name
                    	local start_bit, end_bit = reverse_range(field.range)
                    	local value = binary_str:sub(start_bit + 1, end_bit + 1) -- Lua is 1-based
                	fields[name] = value
        	end
        end

	return fields
end

function decode_common.decode_inst_name_from_opcode(instruction_table, group_name, opcode)
	local opcode_dec = tonumber(opcode, 2)
	if not instruction_table[group_name] then return "Unknown group name '"..group_name.."'" end
	if not instruction_table[group_name][opcode_dec] then return "Unknown opcode '"..opcode_dec.."' for group '"..group_name.."'" end
	return instruction_table[group_name][opcode_dec].instruction_name
end

return decode_common
