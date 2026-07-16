MOD = 9901
local line = io.read()
local a, b = line:match("(%d+)%s(%d+)")
a, b = tonumber(a), tonumber(b)
local function quick_pow(a, b)
	local res = 1
	while b > 0 do
		if (b & 1) == 1 then
			res = res * a % MOD
		end
		a = a * a % MOD
		b = b >> 1
	end
	return res
end
local top = quick_pow(a, b)
local hash = { 1 }
local curIndex = 2
while curIndex <= a do
  if a % curIndex ~= 0 then
    curIndex = curIndex + 1
    goto continue
  end
  hash[#hash] = curIndex
  a = a // curIndex
  ::continue::
end
local vector = {}
local function bfs(cur)
	vector[#vector + 1] = cur
	for i = 1, #hash do
		next = cur * hash[i]
		if next > top then
			return
		end
		bfs(next)
	end
end
bfs(1)
local res = 0
for i = 1, #vector do
	res = (res % MOD) + (vector[i] % MOD) % MOD
end
print(res)
