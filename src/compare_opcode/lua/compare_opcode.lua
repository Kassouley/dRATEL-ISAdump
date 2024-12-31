require("string_ext")
local lfs = require("lfs")
local csv_parser = require("csv_parser")
local decode_common = require("decode_common")
local binary_format = require("binary_format")


local function parse_encoding_map(csv_path)
	local ret = {}
	local file = lfs.open_file(csv_path)
	file:read()
	for line in file:lines() do
		col = line:trim():split(",")
		ret[col[1]:lower()] = col[2]
	end
	return ret
end

local function parse_opcode_map(csv_path)
	local ret = {}
	local file = lfs.open_file(csv_path)
	file:read()
	for line in file:lines() do
		col = line:split(",")
		ret[col[4]:lower()] = col[3]
	end
	return ret
end

local encoding_map = parse_encoding_map("test.csv")
local opcode_map = parse_opcode_map("instructions.csv")
local encoding_table = csv_parser.get_encoding_table("encoding.csv")
local sorted_encoding_table = {}

for key, entry in pairs(encoding_table) do
	table.insert(sorted_encoding_table, entry)
end

table.sort(sorted_encoding_table, function(a, b)
        return #a.encoding > #b.encoding
end)


for inst, encoding in pairs(encoding_map) do
	if encoding ~= "" then
		local dword = encoding:split()[1]
		local binary_string = binary_format.hex_to_bin(dword)
		local group = decode_common.decode_inst_group(binary_string, sorted_encoding_table)
		local fields = decode_common.decode_fields_from_group(binary_string, group)
		local group_name = group.name
		
		local opcode = tonumber(fields.OP, 2)

		if opcode_map[inst] and opcode and tonumber(opcode_map[inst]) ~= tonumber(opcode) then
			print(binary_string, group_name,inst..": "..opcode_map[inst] .. " != " .. opcode)
		end
	end
end
