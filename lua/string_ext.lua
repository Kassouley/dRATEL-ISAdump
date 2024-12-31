-- string_ext.lua

--- Trims leading and trailing whitespace from a string and replaces multiple spaces with a single space.
-- @param s The string to trim.
-- @return The trimmed string.
function string:trim()
    return self:match("^%s*(.-)%s*$")
end

--- Splits a string by a delimiter.
-- @param str The string to split.
-- @param delimiter The delimiter to split by.
-- @return A table containing the split parts of the string.
function string:split(delimiter)
    delimiter = delimiter or " "
    local result = {}
    local pattern = string.format("([^%s]*)", delimiter)
    for match in string.gmatch(self, pattern) do
        table.insert(result, match)
    end
    return result
end

--- Splits a string outside of specified scope delimiters.
-- Splits the string based on a separator, but only outside of a specified scope (e.g., parentheses).
-- @param str The string to split.
-- @param sep The separator to use (default is comma).
-- @param scope_open The opening scope character (default is "(").
-- @param scope_close The closing scope character (default is ")").
-- @return A table containing the split parts of the string.
function string:split_outside_scope(sep, scope_open, scope_close)
    local result = {}
    local scope_level = 0
    local start_index = 1
    sep = sep or ","
    scope_open = scope_open or "("
    scope_close = scope_close or ")"
    
    for i = 1, #str do
        local char = str:sub(i, i)
        
        if char == scope_open then
            scope_level = scope_level + 1
        elseif char == scope_close then
            scope_level = scope_level - 1
        elseif char == sep and scope_level == 0 then
            table.insert(result, common.trim(str:sub(start_index, i-1)))
            start_index = i + 1
        end
    end
    
    table.insert(result, common.trim(str:sub(start_index)))
    
    return result
end

-- Check if a string starts with a given prefix
function string:startswith(prefix)
    return self:sub(1, #prefix) == prefix
end

-- Check if a string ends with a given suffix
function string:endswith(suffix)
    return self:sub(-#suffix) == suffix
end

-- Convert a string to title case
function string:titlecase()
    return self:gsub("(%a)([%w_']*)", function(first, rest)
        return first:upper() .. rest:lower()
    end)
end

-- Count the number of occurrences of a substring in a string
function string:count(substring)
    local count = 0
    local start = 1
    while true do
        local pos = self:find(substring, start, true)
        if not pos then break end
        count = count + 1
        start = pos + #substring
    end
    return count
end

-- Pad a string to a given length with a specified character (default is space)
function string:pad(length, char)
    char = char or " "
    if #self >= length then return self end
    local pad_length = length - #self
    local left_pad = string.rep(char, math.floor(pad_length / 2))
    local right_pad = string.rep(char, math.ceil(pad_length / 2))
    return left_pad .. self .. right_pad
end
