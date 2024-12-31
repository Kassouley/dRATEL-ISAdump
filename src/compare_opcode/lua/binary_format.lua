local binary_format = {}

function binary_format.reverse_endianness(hex_string)
    if #hex_string ~= 8 then
        return "Invalid input: Hex string must be 8 characters (32-bit)."
    end

    local byte1 = hex_string:sub(1, 2)
    local byte2 = hex_string:sub(3, 4)
    local byte3 = hex_string:sub(5, 6)
    local byte4 = hex_string:sub(7, 8)

    return byte4 .. byte3 .. byte2 .. byte1
end

function binary_format.hex_to_bin(hex_string)
    local hex_to_bin_map = {
        ['0'] = '0000', ['1'] = '0001', ['2'] = '0010', ['3'] = '0011',
        ['4'] = '0100', ['5'] = '0101', ['6'] = '0110', ['7'] = '0111',
        ['8'] = '1000', ['9'] = '1001', ['A'] = '1010', ['B'] = '1011',
        ['C'] = '1100', ['D'] = '1101', ['E'] = '1110', ['F'] = '1111',
        ['a'] = '1010', ['b'] = '1011', ['c'] = '1100', ['d'] = '1101',
        ['e'] = '1110', ['f'] = '1111'
    }
    
    local binary_string = ""

    for i = 1, #hex_string do
        local hex_char = string.sub(hex_string, i, i)  
        if hex_char ~= " " then
		local binary = hex_to_bin_map[hex_char]
        
        	if binary then
            		binary_string = binary_string .. binary
        	else
            		error("Invalid hexadecimal character: <<" .. hex_char..">> in string: <<"..hex_string..">>")
        	end
    	end
    end
    return binary_string
end

return binary_format
