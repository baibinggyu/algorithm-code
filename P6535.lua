local res = "PREDAJA"
local n = tonumber(io.read())
-- local arr = {}
local t = {}
for i = 1, n do
	local str = io.read()
	local first = str:sub(1, 1)
	t[first] = (t[first] or 0) + 1
end
local str_list = {}
for key, value in pairs(t) do
	if value >= 5 then
		str_list[#str_list + 1] = key
	end
end
table.sort(str_list)
if #str_list == 0 then
	print(res)
else
	for _, ch in ipairs(str_list) do
		io.write(ch)
	end
end
