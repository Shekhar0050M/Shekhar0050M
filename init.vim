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
"''Navigation Plugins''"
Plug 'rbgrouleff/bclose.vim'
"Plug 'dbakker/vim-projectroot'
Plug 'majutsushi/tagbar'
Plug 'scrooloose/nerdtree'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'

"'' Git Support ''"
"Plug 'rhysd/git-messenger.vim'
"Plug 'ThePrimeagen/git-worktree.nvim'
"Plug 'lewis6991/gitsigns.nvim'

"'' Language Support ''"
Plug 'neoclide/coc.nvim', { 'branch': 'release' }
"Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
"Plug 'jparise/vim-graphql'

"'' Themes ''"
Plug 'ghifarit53/tokyonight-vim'

"'' Utilities ''"
"Plug 'phaazon/hop.nvim'
"Plug 'itchyny/lightline.vim'
"Plug 'preservim/nerdcommenter'
"Plug 'romgrk/nvim-treesitter-context'
Plug 'ryanoasis/vim-devicons'
" Plug 'vim-scripts/ReplaceWithRegister'
"Plug 'voldikss/vim-floaterm'
"Plug 'takac/vim-hardtime' " see http://vimcasts.org/blog/2013/02/habit-breaking-habit-making/
" Plug 'mg979/vim-visual-multi', { 'branch': 'master' }
Plug 'bling/vim-bufferline'
"Plug 'tibabit/vim-templates'
Plug 'scrooloose/nerdcommenter'
"Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'jiangmiao/auto-pairs'
"Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'frazrepo/vim-rainbow'
"Plug 'tmhedberg/SimpylFold', { 'for': 'python' }
"Plug 'vim-utils/vim-man'
"Plug 'mbbill/undotree'
"Plug 'tpope/vim-dispatch'
"Plug 'theprimeagen/vim-be-good'
Plug 'octol/vim-cpp-enhanced-highlight'
"Plug 'tpope/vim-projectionist'
"Plug 'lifepillar/vim-solarized8'
"'' VimWiki + Zettelkasten ''"
Plug 'vimwiki/vimwiki'
"Plug 'lukaszkorecki/workflowish'
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'
"Plug 'michal-h21/vim-zettel'

"''Cimpetitive Coding''"
Plug 'searleser97/cpbooster.vim'

" Debugger Plugins
"Plug 'puremourning/vimspector'
"Plug 'szw/vim-maximizer'

" telescope requirements...
"Plug 'nvim-lua/popup.nvim'
"Plug 'nvim-lua/plenary.nvim'
"Plug 'nvim-telescope/telescope.nvim'
"Plug 'nvim-telescope/telescope-fzy-native.nvim'
"Plug 'colepeters/spacemacs-theme.vim'

"Plug 'sainnhe/gruvbox-material'
"Plug 'phanviet/vim-monokai-pro'
Plug 'flazz/vim-colorschemes'
"Plug 'chriskempson/base16-vim'
"Plug 'dracula/vim', { 'as': 'dracula' }

" HARPOON!!
"Plug 'mhinz/vim-rfc'
"Plug 'ThePrimeagen/neovim-irc-ui'

" should I try another status bar???
"  Plug 'glepnir/galaxyline.nvim' , {'branch': 'main'}
" Plug 'hoob3rt/lualine.nvim'

" Web development
Plug 'mattn/emmet-vim'
"Plug 'yuezk/vim-js'
"Plug 'maxmellon/vim-jsx-pretty'
"Plug 'alvan/vim-closetag'

" AutoCompletions...
"Plug 'codota/tabnine-vim'

call plug#end()

"'' END PLUG ''"

let g:user_emmet_install_global = 0
autocmd FileType html,css EmmetInstall

"'' VIM POST-PLUG ''"
"''Airline''"

let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline_powerline_fonts = 1
let g:airline_theme = "tokyonight"
let g:tokyonight_style = 'storm' " available: night, storm
let g:tokyonight_enable_italic = 0
let g:vim_be_good_log_file = 1
let g:vim_apm_log = 1
colorscheme tokyonight
map <Esc><Esc> :qa <CR>
map <F2> :Test <CR>
map <F3> :Debug <CR>
map <Esc> :q <CR>
map <F4> :Termdebug <CR>
autocmd CursorHold * update
nmap <Leader>n :NERDTreeToggle<CR>
set rtp^=/usr/share/vim/vimfiles

filetype plugin indent on

autocmd FileType html,css syntax on
autocmd BufRead,BufNewFile *.sage,*.pyx,*.spyx set filetype=python
packadd termdebug
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



"'' VIM Keymaps ''"
nmap <leader>h :wincmd h<CR>
nmap <leader>j :wincmd j<CR>
nmap <leader>k :wincmd k<CR>
nmap <leader>l :wincmd l<CR>

"'' Conquer of Completion (CoC) ''"
if filereadable(expand("~/.config/nvim/plugged/coc.nvim/plugin/coc.vim"))
    let g:coc_global_extensions=[
                \'coc-actions',
                \'coc-clangd',
                \'coc-emmet',
                \'coc-html',
                \'coc-css',
                \'coc-tabnine',
                \'coc-tsserver',
                \'coc-marketplace',
                \'coc-highlight']

    " Always show the signcolumn, otherwise it would shift the text each time
    set encoding=UTF-8
    " diagnostics appear/become resolved.
    if has("patch-8.1.1564")
        " Recently vim can merge signcolumn and number column into one
        set signcolumn=number
    else
        set signcolumn=yes
    endif

    " Use tab for trigger completion with characters ahead and navigate.
    " NOTE: Use command ':verbose imap <tab>' to make sure tab is not mapped by
    " other plugin before putting this into your config.
    inoremap <silent><expr> <TAB>
                \ pumvisible() ? "\<C-n>" :
                \ <SID>check_back_space() ? "\<TAB>" :
                \ coc#refresh()
    inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"

    function! s:check_back_space() abort
        let col = col('.') - 1
        return !col || getline('.')[col - 1]  =~# '\s'
    endfunction

    " Use <c-space> to trigger completion.
    if has('nvim')
        inoremap <silent><expr> <c-space> coc#refresh()
    else
        inoremap <silent><expr> <c-@> coc#refresh()
    endif

    " Make <CR> auto-select the first completion item and notify coc.nvim to
    " format on enter, <cr> could be remapped by other vim plugin
    inoremap <silent><expr> <cr> pumvisible() ? coc#_select_confirm()
                \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

    " Use `[g` and `]g` to navigate diagnostics
    " Use `:CocDiagnostics` to get all diagnostics of current buffer in location list.
    nmap <silent> [g <Plug>(coc-diagnostic-prev)
    nmap <silent> ]g <Plug>(coc-diagnostic-next)

    " GoTo code navigation.
    nmap <leader>bd <Plug>(coc-definition)
    nmap <leader>bt <Plug>(coc-type-definition)
    nmap <leader>bi <Plug>(coc-implementation)
    nmap <leader>br <Plug>(coc-references)

    " Use K to show documentation in preview window.
    nnoremap <silent> K :call <SID>show_documentation()<CR>

    function! s:show_documentation()
        if (index(['vim','help'], &filetype) >= 0)
            execute 'h '.expand('<cword>')
        elseif (coc#rpc#ready())
            call CocActionAsync('doHover')
        else
            execute '!' . &keywordprg . " " . expand('<cword>')
        endif
    endfunction

    " Highlight the symbol and its references when holding the cursor.
    autocmd CursorHold * silent call CocActionAsync('highlight')

    " Symbol renaming.
    nmap <leader>rn <Plug>(coc-rename)

    " Formatting selected code.
    xmap <leader>f  <Plug>(coc-format-selected)
    nmap <leader>f  <Plug>(coc-format-selected)

    augroup mygroup
        autocmd!
        " Setup formatexpr specified filetype(s).
        autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
        " Update signature help on jump placeholder.
        autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
    augroup end

    " Applying codeAction to the selected region.
    " Example: `<leader>aap` for current paragraph
    xmap <leader>a  <Plug>(coc-codeaction-selected)
    nmap <leader>a  <Plug>(coc-codeaction-selected)

    " Remap keys for applying codeAction to the current buffer.
    nmap <leader>ac  <Plug>(coc-codeaction)
    " Apply AutoFix to problem on the current line.
    nmap <leader>qf  <Plug>(coc-fix-current)

    " Map function and class text objects
    " NOTE: Requires 'textDocument.documentSymbol' support from the language server.
    xmap if <Plug>(coc-funcobj-i)
    omap if <Plug>(coc-funcobj-i)
    xmap af <Plug>(coc-funcobj-a)
    omap af <Plug>(coc-funcobj-a)
    xmap ic <Plug>(coc-classobj-i)
    omap ic <Plug>(coc-classobj-i)
    xmap ac <Plug>(coc-classobj-a)
    omap ac <Plug>(coc-classobj-a)

    " Remap <C-f> and <C-b> for scroll float windows/popups.
    if has('nvim-0.4.0') || has('patch-8.2.0750')
        nnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
        nnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
        inoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? "\<c-r>=coc#float#scroll(1)\<cr>" : "\<Right>"
        inoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? "\<c-r>=coc#float#scroll(0)\<cr>" : "\<Left>"
        vnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
        vnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
    endif

    " Use CTRL-S for selections ranges.
    " Requires 'textDocument/selectionRange' support of language server.
    nmap <silent> <C-s> <Plug>(coc-range-select)
    xmap <silent> <C-s> <Plug>(coc-range-select)

    " Add `:Format` command to format current buffer.
    command! -nargs=0 Format :call CocAction('format')

    " Add `:Fold` command to fold current buffer.
    command! -nargs=? Fold :call     CocAction('fold', <f-args>)

    " Add `:OR` command for organize imports of the current buffer.
    command! -nargs=0 OR   :call     CocAction('runCommand', 'editor.action.organizeImport')

    " Add (Neo)Vim's native statusline support.
    " NOTE: Please see `:h coc-status` for integrations with external plugins that
    " provide custom statusline: lightline.vim, vim-airline.
    set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}

    " Mappings for CoCList
    " Show all diagnostics.
    nnoremap <silent><nowait> <space>a  :<C-u>CocList diagnostics<cr>
    " Manage extensions.
    nnoremap <silent><nowait> <space>e  :<C-u>CocList extensions<cr>
    " Show commands.
    nnoremap <silent><nowait> <space>c  :<C-u>CocList commands<cr>
    " Find symbol of current document.
    nnoremap <silent><nowait> <space>o  :<C-u>CocList outline<cr>
    " Search workspace symbols.
    nnoremap <silent><nowait> <space>s  :<C-u>CocList -I symbols<cr>
    " Do default action for next item.
    nnoremap <silent><nowait> <space>j  :<C-u>CocNext<CR>
    " Do default action for previous item.
    nnoremap <silent><nowait> <space>k  :<C-u>CocPrev<CR>
    " Resume latest coc list.
    nnoremap <silent><nowait> <space>p  :<C-u>CocListResume<CR>
endif

let g:bufferline_rotate=1
let g:bufferline_fixed_index=-1
let g:bufferline_echo = 0

let g:vimwiki_list = [{'path': '~/Shekhar0050M/vimwiki/', 'syntax': 'default'},
            \ {'path': '~/Shekhar0050M/projectwiki/', 'syntax': 'default'}]

"com -range=% -nargs=1 P exe "<line1>,<line2>!".<q-args> | y | sil u | echom @"
"com -range=% Hash <line1>,<line2>P cpp -P -fpreprocessed | tr -d '[:space:]' | md5sum
"au FileType cpp com! -buffer -range=% Hash <line1>,<line2>P cpp -P -fpreprocessed | tr -d '[:space:]' | md5sum

"nmap <leader>sp :call <SID>SynStack()<CR>
"function! <SID>SynStack()
"if !exists("*synstack")
"return
"endif
"echo map(synstack(line('.'), col('.')), 'synIDattr(v:val, "name")')
"endfunc

"'' Floatterm ''"
"if filereadable(expand("~/.config/nvim/plugged/vim-floaterm/plugin/floaterm.vim"))
"nnoremap <leader>fd :FloatermNew --autoclose=2 --height=0.9 --width=0.9 --wintype=floating lazydocker<CR>
"nnoremap <leader>fg :FloatermNew --autoclose=2 --height=0.9 --width=0.9 --wintype=floating lazygit<CR>
"nnoremap <leader>fr :FloatermNew --autoclose=2 --height=0.75 --width=0.75 --wintype=floating ranger<CR>
"nnoremap <leader>ft :FloatermNew --autoclose=2 --height=0.9 --width=0.9 --wintype=floating<CR>
"endif

"noremap <silent> <Leader>w :call ToggleWrap()<CR>
"function WrapOn()
"setlocal wrap linebreak
"set virtualedit=
"setlocal display+=lastline
"noremap  <buffer> <silent> <Up>   g<Up>
"noremap  <buffer> <silent> <Down> g<Down>
"noremap  <buffer> <silent> <Home> g<Home>
"noremap  <buffer> <silent> <End>  g<End>
"inoremap <buffer> <silent> <Up>   <C-o>gk
"inoremap <buffer> <silent> <Down> <C-o>gj
"inoremap <buffer> <silent> <Home> <C-o>g<Home>
"inoremap <buffer> <silent> <End>  <C-o>g<End>
"endfunction
"function WrapOff()
"setlocal nowrap
"set virtualedit=
"silent! nunmap <buffer> <Up>
"silent! nunmap <buffer> <Down>
"silent! nunmap <buffer> <Home>
"silent! nunmap <buffer> <End>
"silent! iunmap <buffer> <Up>
"silent! iunmap <buffer> <Down>
"silent! iunmap <buffer> <Home>
"silent! iunmap <buffer> <End>
"endfunction
"function ToggleWrap()
"if &wrap
"echo "Wrap OFF"
"call WrapOff()
"else
"echo "Wrap ON"
"call WrapOn()
"endif
"endfunction
"call WrapOn()

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
" Project root
let g:rootmarkers = ['.projectroot','Makefile','.git','.hg','.svn','.bzr','_darcs','build.xml']

" FZF configs
let $FZF_DEFAULT_COMMAND = 'rg --files'
let g:fzf_command_prefix = 'Fzf'
let g:fzf_buffers_jump = 1
"command! FzfProjectFiles execute 'FzfFiles' projectroot#guess()
nnoremap <silent> <Leader><Space> :FzfFiles<CR>
nnoremap <silent> <Leader>f :FzfRg<CR>
nnoremap <silent> <Leader>a :FzfBuffers<CR>
nnoremap <silent> <Leader>A :FzfWindows<CR>


""'' Git-worktree ''"
"if filereadable(expand("~/.config/nvim/plugged/git-worktree.nvim/lua/git-worktree/init.lua"))
"lua require("git-worktree").setup()

"nnoremap <leader>gc <CMD>lua require("git-worktree").create_worktree(vim.fn.input("Worktree name > "), vim.fn.input("Worktree upstream > "))<CR>
"endif


""'' Gitsigns ''"
"if filereadable(expand("~/.config/nvim/plugged/gitsigns.nvim/lua/gitsigns.lua"))
"lua require('gitsigns').setup()
"endif


"'' Hardtime ''"
"if filereadable(expand("~/.config/nvim/plugged/vim-hardtime/plugin/hardtime.vim"))
"let g:hardtime_default_on = 1
"let g:hardtime_showmsg = 1
"endif


"'' Hop ''"
"if filereadable(expand("~/.config/nvim/plugged/hop.nvim/plugin/hop.vim"))
"nnoremap <leader>h1 :HopChar1<CR>
"nnoremap <leader>h2 :HopChar2<CR>
"nnoremap <leader>hh :HopPattern<CR>
"nnoremap <leader>hw :HopWord<CR>
"endif


"'' Lightline ''"
"if filereadable(expand("~/.config/nvim/plugged/lightline.vim/plugin/lightline.vim"))
"let g:lightline = {'colorscheme' : 'tokyonight'}
"endif


""'' Telescope ''"
"if filereadable(expand("~/.config/nvim/plugged/telescope.nvim/plugin/telescope.vim"))
"lua << EOF
"require('telescope').setup{
"defaults = {
"file_ignore_patterns = {
""%.git/.*",
""node_modules/.*",
""secret.d/.*",
""%.pem"
"}
"}
"}
"EOF
"if filereadable(expand("~/.config/nvim/plugged/git-worktree.nvim/lua/git-worktree/init.lua"))
"lua require("telescope").load_extension("git_worktree")
"endif

"nnoremap <leader>fe <CMD>lua require('telescope.builtin').file_browser{cwd = vim.fn.expand("%:p:h")}<CR>
"nnoremap <leader>ff <CMD>lua require('telescope.builtin').find_files{ hidden = true }<CR>
"nnoremap <leader>fs <CMD>lua require('telescope.builtin').live_grep()<CR>
"nnoremap <leader>fb <CMD>lua require('telescope.builtin').buffers()<CR>
"nnoremap <leader>fh <CMD>lua require('telescope.builtin').help_tags()<CR>
"nnoremap <leader>fw <CMD>lua require('telescope').extensions.git_worktree.git_worktrees()<CR>
"endif


""'' Treesitter ''"
"if filereadable(expand("~/.config/nvim/plugged/nvim-treesitter/plugin/nvim-treesitter.vim"))
"lua require'nvim-treesitter.configs'.setup{ ensure_installed='all', highlight={ enable=true } }
"endif


"'' VIM Zettel ''"
"if filereadable(expand("~/.config/nvim/plugged/vim-zettel/plugin/zettel.vim"))
"nnoremap <leader>zn :ZettelNew<CR>
"nnoremap <leader>zo :ZettelOpen<CR>
"nnoremap <leader>zi :ZettelInsertNote<CR>
"nnoremap <leader>zb :ZettelBackLinks<CR>
"nnoremap <leader>zu :ZettelInbox<CR>
"nnoremap <leader>zl :ZettelGenerateLinks<CR>
"nnoremap <leader>zt :ZettelGenerateTags<CR>
"nnoremap <leader>zs :ZettelSearch<CR>
"nnoremap <leader>zy :ZettelYankName<CR>
"endif
