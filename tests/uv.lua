local uv = require("lasyncio.uv")

if uv.open_el() then
	print("event loop opened successfully")
else
	print("failed to init the loop")
end

if uv.close_el() then
	print("event loop closed successfully")
else
	print("failed to close the loop")
end
