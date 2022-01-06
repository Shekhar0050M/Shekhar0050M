"'' VIM PRE-PLUG ''"
set hidden
set nobackup
set nocompatible
set nowritebackup
set secure
set shortmess+=c
set termguicolors
set updatetime=300
filetype off
syntax enable
"'' Definitions ''"
let g:mapleader="\<Space>"
let g:maplocalleader="\<Space>"

"'' START PLUG ''"
call plug#begin('~/.config/nvim/plugged')

Plug 'rbgrouleff/bclose.vim'
Plug 'majutsushi/tagbar'
Plug 'scrooloose/nerdtree'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'ghifarit53/tokyonight-vim'
Plug 'preservim/nerdcommenter'
Plug 'ryanoasis/vim-devicons'
Plug 'bling/vim-bufferline'
Plug 'tibabit/vim-templates'
Plug 'airblade/vim-gitgutter'
Plug 'jiangmiao/auto-pairs'
Plug 'frazrepo/vim-rainbow'
Plug 'mbbill/undotree'
Plug 'vimwiki/vimwiki'
Plug 'searleser97/cpbooster.vim'
Plug 'puremourning/vimspector'
Plug 'szw/vim-maximizer'
Plug 'flazz/vim-colorschemes'
Plug 'alvan/vim-closetag'
Plug 'ycm-core/YouCompleteMe'
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
Plug 'nvim-treesitter/playground'

call plug#end()

"'' VIM POST-PLUG ''"
"'' YCM ''"
set encoding=utf-8
"let g:ycm_java_jdtls_extension_path = [
  "\ '</home/shekhar/.vim/vimspector-config/gadgets/linux'
  "\ ]
nmap <Leader>qf :YcmCompleter FixIt<CR>

"''Airline''"

let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline_powerline_fonts = 1
let g:airline_theme = "tokyonight"
let g:tokyonight_style = 'storm' " available: night, storm
let g:tokyonight_enable_italic = 0
let g:vim_be_good_log_file = 1
let g:vim_apm_log = 1
autocmd filetype * colorscheme tokyonight
map <Esc><Esc> :qa <CR>
nmap <F7> :Debug <CR>
map <Esc> :q <CR>
nmap <C-c> :w !xsel -b<CR><CR>
autocmd CursorHold * update
nmap <Leader>n :NERDTreeToggle<CR>
set rtp^=/usr/share/vim/vimfiles
autocmd filetype python,java.cpp,vim colorscheme tokyonight
"'''Vimspector'''"
packadd! vimspector
let g:vimspector_enable_mappings = 'HUMAN'
let g:vimspector_base_dir=expand( '$HOME/.vim/vimspector-config/'  )
filetype plugin indent on
autocmd FileType html,css syntax on
autocmd BufRead,BufNewFile *.sage,*.pyx,*.spyx set filetype=python
"packadd termdebug
set mouse=a
set backspace=indent,eol,start
set softtabstop=4
set shiftwidth=4
set tabstop=4
set expandtab
set number
set ruler
set showcmd
set errorformat^=%-GIn\ file\ included\ %.%#
set foldmethod=syntax
set conceallevel=2
set list lcs=tab:»\ ,trail:␣,extends:▶,precedes:◀
set undofile
set noerrorbells
set cindent cinoptions=N-s,g0,j1,(s,m1
set noshowmode
hi Normal guibg=NONE ctermbg=NONE
hi EndOfBuffer guibg=NONE ctermbg=NONE
set splitright splitbelow
"belowright terminal
set ignorecase smartcase

augroup WrapInMarkdown
    autocmd!
    autocmd FileType markdown setlocal wrap
augroup END

"'''VIM Templates''*
let g:tmpl_author_name='Shekhar Suman'
let g:tmpl_author_email='shekhar0050m@gmail.com'

"'' VIM Keymaps ''"
nmap <leader>h :wincmd h<CR>
nmap <leader>j :wincmd j<CR>
nmap <leader>k :wincmd k<CR>
nmap <leader>l :wincmd l<CR>

let g:bufferline_rotate=1
let g:bufferline_fixed_index=-1
let g:bufferline_echo = 0

let g:vimwiki_list = [{'path': '~/Shekhar0050M/vimwiki/', 'syntax': 'default'},
            \ {'path': '~/Shekhar0050M/projectwiki/', 'syntax': 'default'}]

highlight! link SignColumn LineNr

set spellfile=~/.vim/spell/en.utf-8.add

set laststatus=2
set printoptions+=paper:letter

"''Rainbow''"
let g:rainbow_active = 1
let g:rainbow_load_separately = [
            \ [ '*' , [['(', ')'], ['\[', '\]'], ['{', '}']] ],
            \ [ '*.tex' , [['(', ')'], ['\[', '\]']] ],
            \ [ '*.cpp' , [['(', ')'], ['\[', '\]'], ['{', '}']] ],
            \ [ '*.{html,htm}' , [['(', ')'], ['\[', '\]'], ['{', '}'], ['<\a[^>]*>', '</[^>]*>']] ],
            \ ]

let g:rainbow_guifgs = ['RoyalBlue3', 'DarkOrange3', 'DarkOrchid3', 'FireBrick']
let g:rainbow_ctermfgs = ['lightblue', 'lightgreen', 'yellow', 'red', 'magenta']
autocmd BufNewFile,BufReadPost *.md set filetype=markdown

autocmd StdinReadPre * let s:std_in=1
if has('nvim')
    tnoremap <S-Esc> <Esc>
    tnoremap <Esc> <C-\><C-n>
    autocmd TermOpen * startinsert
    au FileType fzf tnoremap <buffer> <Esc> <Esc>
endif

