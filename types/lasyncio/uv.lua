---@meta

---@class lasyncio.uv
local uv = {}

---Initialize the libuv loop.
---Returns:
---  1: Success
--- -1: Already initialized
--- -2: Error (check logs)
---@return 1 | -1 | -2
---@nodiscard
function uv.open_el() end

---Close the libuv loop.
---Returns:
---  1: Success
--- -1: Not initialized
--- -2: Error (loop still has active handles)
---@return 1 | -1 | -2
---@nodiscard
function uv.close_el() end

return uv
