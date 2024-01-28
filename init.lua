vim.opt.termguicolors = true
vim.g.mapleader = ' '
vim.g.maplocalleader = ' '

vim.fn['plug#begin']()

vim.cmd[[Plug 'ldelossa/nvim-ide']]
vim.cmd[[Plug 'nvim-lua/plenary.nvim']]
vim.cmd[[Plug 'nvim-telescope/telescope.nvim', { 'tag': '0.1.5' }]]
vim.cmd[[Plug 'rcarriga/nvim-notify']]
vim.cmd[[Plug 'dnlhc/glance.nvim']]
vim.cmd[[Plug 'lewis6991/gitsigns.nvim']]
vim.cmd[[Plug 'ibhagwan/fzf-lua', {'branch': 'main'}]]
vim.cmd[[Plug 'nvim-tree/nvim-web-devicons']]
vim.cmd[[Plug 'mfussenegger/nvim-dap']]
vim.cmd[[Plug 'rcarriga/nvim-dap-ui']]
vim.cmd[[Plug 'ghifarit53/tokyonight-vim']]
vim.cmd[[Plug 'vim-airline/vim-airline']]
vim.cmd[[Plug 'vim-airline/vim-airline-themes']]
vim.cmd[[Plug 'bling/vim-bufferline']]
vim.cmd[[Plug 'flazz/vim-colorschemes']]
vim.cmd[[Plug 'vimwiki/vimwiki']]
vim.cmd [[Plug 'neovim/nvim-lspconfig']]

vim.fn['plug#end']()

-- default components
local bufferlist      = require('ide.components.bufferlist')
local explorer        = require('ide.components.explorer')
local outline         = require('ide.components.outline')
local callhierarchy   = require('ide.components.callhierarchy')
local timeline        = require('ide.components.timeline')
local terminal        = require('ide.components.terminal')
local terminalbrowser = require('ide.components.terminal.terminalbrowser')
local changes         = require('ide.components.changes')
local commits         = require('ide.components.commits')
local branches        = require('ide.components.branches')
local bookmarks       = require('ide.components.bookmarks')

require('ide').setup({
    -- The global icon set to use.
    -- values: "nerd", "codicon", "default"
    icon_set = "default",
    -- Set the log level for nvim-ide's log. Log can be accessed with 
    -- 'Workspace OpenLog'. Values are 'debug', 'warn', 'info', 'error'
    log_level = "info",
    -- Component specific configurations and default config overrides.
    components = {
        -- The global keymap is applied to all Components before construction.
        -- It allows common keymaps such as "hide" to be overridden, without having
        -- to make an override entry for all Components.
        --
        -- If a more specific keymap override is defined for a specific Component
        -- this takes precedence.
        global_keymaps = {
            -- example, change all Component's hide keymap to "h"
            -- hide = h
        },
        -- example, prefer "x" for hide only for Explorer component.
        -- Explorer = {
        --     keymaps = {
        --         hide = "x",
        --     }
        -- }
    },
    -- default panel groups to display on left and right.
    panels = {
        left = "explorer",
        right = "git",
    },
    -- panels defined by groups of components, user is free to redefine the defaults
    -- and/or add additional.
    panel_groups = {
        explorer = { outline.Name, bufferlist.Name, explorer.Name, bookmarks.Name, callhierarchy.Name, terminalbrowser.Name },
        terminal = { terminal.Name },
        git = { changes.Name, commits.Name, timeline.Name, branches.Name }
    },
    -- workspaces config
    workspaces = {
        -- which panels to open by default, one of: 'left', 'right', 'both', 'none'
        auto_open = 'both',
    },
    -- default panel sizes for the different positions
    panel_sizes = {
        left = 30,
        right = 30,
        bottom = 15
    }
})

local builtin = require('telescope.builtin')
vim.keymap.set('n', '<leader>ff', builtin.find_files, {})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})
vim.keymap.set('n', '<leader>fb', builtin.buffers, {})
vim.keymap.set('n', '<leader>fh', builtin.help_tags, {})

require("notify")("My super important message")

-- Lua configuration
local glance = require('glance')
local actions = glance.actions

glance.setup({
  height = 18, -- Height of the window
  zindex = 45,

  -- By default glance will open preview "embedded" within your active window
  -- when `detached` is enabled, glance will render above all existing windows
  -- and won't be restiricted by the width of your active window
  detached = true,

  -- Or use a function to enable `detached` only when the active window is too small
  -- (default behavior)
  detached = function(winid)
    return vim.api.nvim_win_get_width(winid) < 100
  end,

  preview_win_opts = { -- Configure preview window options
    cursorline = true,
    number = true,
    wrap = true,
  },
  border = {
    enable = false, -- Show window borders. Only horizontal borders allowed
    top_char = '―',
    bottom_char = '―',
  },
  list = {
    position = 'right', -- Position of the list window 'left'|'right'
    width = 0.33, -- 33% width relative to the active window, min 0.1, max 0.5
  },
  theme = { -- This feature might not work properly in nvim-0.7.2
    enable = true, -- Will generate colors for the plugin based on your current colorscheme
    mode = 'auto', -- 'brighten'|'darken'|'auto', 'auto' will set mode based on the brightness of your colorscheme
  },
  mappings = {
    list = {
      ['j'] = actions.next, -- Bring the cursor to the next item in the list
      ['k'] = actions.previous, -- Bring the cursor to the previous item in the list
      ['<Down>'] = actions.next,
      ['<Up>'] = actions.previous,
      ['<Tab>'] = actions.next_location, -- Bring the cursor to the next location skipping groups in the list
      ['<S-Tab>'] = actions.previous_location, -- Bring the cursor to the previous location skipping groups in the list
      ['<C-u>'] = actions.preview_scroll_win(5),
      ['<C-d>'] = actions.preview_scroll_win(-5),
      ['v'] = actions.jump_vsplit,
      ['s'] = actions.jump_split,
      ['t'] = actions.jump_tab,
      ['<CR>'] = actions.jump,
      ['o'] = actions.jump,
      ['l'] = actions.open_fold,
      ['h'] = actions.close_fold,
      ['<leader>l'] = actions.enter_win('preview'), -- Focus preview window
      ['q'] = actions.close,
      ['Q'] = actions.close,
      ['<Esc>'] = actions.close,
      ['<C-q>'] = actions.quickfix,
      -- ['<Esc>'] = false -- disable a mapping
    },
    preview = {
      ['Q'] = actions.close,
      ['<Tab>'] = actions.next_location,
      ['<S-Tab>'] = actions.previous_location,
      ['<leader>l'] = actions.enter_win('list'), -- Focus list window
    },
  },
  hooks = {},
  folds = {
    fold_closed = '',
    fold_open = '',
    folded = true, -- Automatically fold list on startup
  },
  indent_lines = {
    enable = true,
    icon = '│',
  },
  winbar = {
    enable = true, -- Available strating from nvim-0.8+
  },
})

require('gitsigns').setup()

vim.keymap.set("n", "<c-P>",
  "<cmd>lua require('fzf-lua').files()<CR>", { silent = true })

vim.opt.undofile = true
vim.opt.spellfile = vim.fn.stdpath('config') .. '/spell/en.utf-8.add'
vim.opt.foldmethod = 'syntax'

-- Airline
vim.g.airline_extensions_tabline_enabled = 1
vim.g.airline_extensions_tabline_left_alt_sep = '|'
vim.g.airline_powerline_fonts = 1
vim.g.airline_theme = "tokyonight"
vim.g.tokyonight_style = "storm"
vim.g.tokyonight_enable_italic = 0
vim.g.vim_be_good_log_file = 1
vim.g.vim_apm_log = 1

-- Set colorscheme based on filetype
vim.api.nvim_exec([[
  augroup AutoCmds
    autocmd!
    autocmd FileType * colorscheme tokyonight
  augroup END
]], false)

require("dapui").setup()

require'nvim-web-devicons'.get_icons()

vim.api.nvim_set_keymap('n', '<Esc><Esc>', ':wqa!<CR>', { noremap = true, silent = true })
-- Auto-save on focus lost or buffer switch
vim.cmd[[
  autocmd BufLeave,FocusLost * silent! wall
]]

-- Set the 'updatetime' option to control the frequency of auto-saving
vim.o.updatetime = 300
-- LSP
local nvim_lsp = require('lspconfig')

vim.lsp.handlers["textDocument/publishDiagnostics"] = vim.lsp.with(
  vim.lsp.diagnostic.on_publish_diagnostics, {
    underline = true,
    virtual_text = {
      spacing = 8,
      severity_limit = "Error",
    },
    signs = false,
    update_in_insert = false,
  }
)
 require'lspconfig'.ui5.setup{}
