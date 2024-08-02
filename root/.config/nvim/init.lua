vim.g.mapleader = ";"
vim.opt.undofile = true
vim.opt.expandtab = true
vim.opt.smartindent = true
vim.opt.shiftwidth = 2
vim.opt.tabstop = 2
vim.opt.mouse = "a"
vim.opt.winwidth = 10
vim.opt.winminwidth = 10
vim.opt.equalalways = true
vim.opt.exrc = true
vim.opt.background = "light"

require("pkgm")

require("plugins.treesitter")
require("plugins.cmp")
require("plugins.coderunner")
require("plugins.tabline")

local opts = {noremap = true, silent = true};
local map = vim.keymap.set

map('n', '<leader>e', '<cmd>Explore<cr>', opts)
map("n", "<leader>n", ":tabnew | Explore<CR>")
map("n", "<leader>t", ":tabnew | terminal<CR>")
map("n", ",", ":tabprev<CR>")
map("n", "<", ":tabmove -1<CR>")
map("n", ">", ":tabmove +1<CR>")
map("n", ".", function()
  if vim.v.count > 0 then
    vim.cmd("tabnext"..vim.v.count)
  else
    vim.cmd "tabnext"
  end
end)
map("t", "<esc>", "<C-\\><C-n>", { noremap = true })

map("n", "<A-1>", ":tabnext 1<CR>")
map("n", "<A-2>", ":tabnext 2<CR>")
map("n", "<A-3>", ":tabnext 3<CR>")
map("n", "<A-4>", ":tabnext 4<CR>")
map("n", "<A-5>", ":tabnext 5<CR>")
map("n", "<A-6>", ":tabnext 6<CR>")
map("n", "<A-7>", ":tabnext 7<CR>")
map("n", "<A-8>", ":tabnext 8<CR>")
map("n", "<A-9>", ":tabnext 9<CR>")
map("n", "<A-0>", ":tabnext 10<CR>")

map("n", "<leader>N", ":nohlsearch<CR>");

vim.cmd('colorscheme edge')
