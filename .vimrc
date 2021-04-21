set nocompatible
filetype off

let g:mapleader="\<Space>"
let g:maplocalleader="\<Space>"

call plug#begin()

"Navigation Plugins
Plug 'rbgrouleff/bclose.vim'
Plug 'dbakker/vim-projectroot'
Plug 'scrooloose/nerdtree'
Plug 'junegunn/fzf'
Plug 'junegunn/fzf.vim'
Plug 'majutsushi/tagbar'

"UI Plugins
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'bling/vim-bufferline'
Plug 'lifepillar/vim-solarized8'
"Editor plugins
Plug 'Raimondi/delimitMate'
Plug 'tibabit/vim-templates'
Plug 'scrooloose/nerdcommenter'
Plug 'tpope/vim-sleuth'
" Plug 'Valloric/YouCompleteMe', { 'do': './install.py --clangd-completer --go-completer --rust-completer --ts-completer' }
" Plug 'rdnetto/ycm-generator', { 'branch': 'stable' }
"Plug 'SirVer/ultisnips'
"Plug 'ludovicchabant/vim-gutentags'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'editorconfig/editorconfig-vim'
Plug 'Chiel92/vim-autoformat'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'frazrepo/vim-rainbow'

"Language specific
Plug 'tmhedberg/SimpylFold', { 'for': 'python' }
"Plug 'lervag/vimtex', { 'for': 'tex' }
"Plug 'vim-pandoc/vim-pandoc'
"Plug 'vim-pandoc/vim-pandoc-syntax'
"Plug 'yuezk/vim-js'
Plug 'HerringtonDarkholme/yats.vim'
"Plug 'leafgarland/typescript-vim'
"Plug 'maxmellon/vim-jsx-pretty'
"Plug 'tikhomirov/vim-glsl'
Plug 'vhdirk/vim-cmake'
"Plug 'ds26gte/scmindent'
"Plug 'udalov/kotlin-vim'

if isdirectory("~/dev/mitscript-syntax")
    Plug '~/dev/mitscript-syntax'
endif

"Note taking
"Plug 'vimwiki/vimwiki'
"Plug 'lukaszkorecki/workflowish'

"Competitive Coding
Plug 'searleser97/cpbooster.vim'

"IDEs
"Plug 'mattn/ideone-vim'
"Plug 'mattn/webapi-vim'

call plug#end()
let g:ideone_browser_command = 'w3m %URL%'
"map <C-x> :!time g++ -std=c++17 % && time ./a.out <CR>
"nmap <C-o> :!./a.out<CR>
map <C-x> :Test <CR>
map <C-o> :Debug <CR>
nmap <C-q> :q <CR>
autocmd CursorHold * update

set rtp^=/usr/share/vim/vimfiles

syntax on
filetype plugin indent on

autocmd BufRead,BufNewFile *.sage,*.pyx,*.spyx set filetype=python

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

set cindent cinoptions=N-s,g0,j1,(s,m1

set splitright splitbelow
"belowright terminal
set ignorecase smartcase
nnoremap * /\<<C-R>=expand('<cword>')<CR>\><CR>
nnoremap # ?\<<C-R>=expand('<cword>')<CR>\><CR>

" Map <CR> to :nohl, except in quickfix windows
nnoremap <silent> <expr> <CR> &buftype ==# 'quickfix' ? "\<CR>" : ":nohl\<CR>"

nnoremap gA :%y+<CR>

" Necessary for terminal buffers not to die
"set hidden
" autocmd TermOpen * set bufhidden=hide

set title

set nojoinspaces

set mouse=a

set autoread
autocmd BufEnter,FocusGained * checktime

" Update gutters 200 ms
set updatetime=200

cmap w!! w !sudo tee > /dev/null %

let g:gutentags_project_root_finder = 'projectroot#guess'
let g:gutentags_generate_on_missing = 0
let g:gutentags_generate_on_new = 0
let g:gutentags_modules = ['ctags', 'cscope']
let g:gutentags_cache_dir = $HOME . '/.cache/gutentags'
let g:gutentags_ctags_tagfile = '.vimtags'
set tags=./.vimtags;,.vimtags,./tags;,tags

" Set internal encoding of vim, not needed on neovim, since coc.nvim using some
" unicode characters in the file autoload/float.vim
set encoding=utf-8

" TextEdit might fail if hidden is not set.
set hidden

" Some servers have issues with backup files, see #649.
set nobackup
set nowritebackup

" Give more space for displaying messages.
set cmdheight=2

" Having longer updatetime (default is 4000 ms = 4 s) leads to noticeable
" delays and poor user experience.
set updatetime=300

" Don't pass messages to |ins-completion-menu|.
set shortmess+=c

" Always show the signcolumn, otherwise it would shift the text each time
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
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

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

let g:python_host_prog = '/usr/bin/python2'
let g:python3_host_prog = '/usr/bin/python3'

let g:ycm_global_ycm_extra_conf = '~/.config/nvim/ycm_global_extra_conf.py'
let g:ycm_autoclose_preview_window_after_insertion = 1

let delimitMate_expand_cr = 1
autocmd FileType tex let b:delimitMate_autoclose = 0

let g:bufferline_rotate=1
let g:bufferline_fixed_index=-1
let g:bufferline_echo = 0

noremap <silent> <Leader>w :call ToggleWrap()<CR>
function WrapOn()
    setlocal wrap linebreak
    set virtualedit=
    setlocal display+=lastline
    noremap  <buffer> <silent> <Up>   g<Up>
    noremap  <buffer> <silent> <Down> g<Down>
    noremap  <buffer> <silent> <Home> g<Home>
    noremap  <buffer> <silent> <End>  g<End>
    inoremap <buffer> <silent> <Up>   <C-o>gk
    inoremap <buffer> <silent> <Down> <C-o>gj
    inoremap <buffer> <silent> <Home> <C-o>g<Home>
    inoremap <buffer> <silent> <End>  <C-o>g<End>
endfunction
function WrapOff()
    setlocal nowrap
    set virtualedit=
    silent! nunmap <buffer> <Up>
    silent! nunmap <buffer> <Down>
    silent! nunmap <buffer> <Home>
    silent! nunmap <buffer> <End>
    silent! iunmap <buffer> <Up>
    silent! iunmap <buffer> <Down>
    silent! iunmap <buffer> <Home>
    silent! iunmap <buffer> <End>
endfunction
function ToggleWrap()
    if &wrap
        echo "Wrap OFF"
        call WrapOff()
    else
        echo "Wrap ON"
        call WrapOn()
    endif
endfunction
call WrapOn()

if $TERM =~ 'rxvt' || $TERM =~'termite'
    let g:solarized_visibility='low'
    set background=dark
    colorscheme solarized
endif

highlight! link SignColumn LineNr

set spellfile=~/.vim/spell/en.utf-8.add

set laststatus=2

let g:airline_powerline_fonts = 1

let g:NERDAltDelims_c = 1

let g:tex_flavor='latex'
if has('nvim')
    let g:vimtex_compiler_progname='nvr'
endif
if has('nvim') && !has('nvim-0.2')
    let g:vimtex_quickfix_latexlog = {'fix_paths':0}
endif
if executable('zathura')
    let g:vimtex_view_method='zathura'
endif
let g:vimtex_quickfix_open_on_warning=0

" lisp/scheme
autocmd filetype lisp,scheme setlocal equalprg=$HOME/.config/nvim/plugged/scmindent/scmindent.rkt

set printoptions+=paper:letter

"Rainbow
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

let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline#extensions#tabline#formatter = 'default'
let g:airline#extensions#wordcount#enabled = 1
let g:airline#extensions#wordcount#filetypes = ['help', 'markdown', 'rst', 'org', 'text', 'asciidoc', 'tex', 'mail']
let g:airline#extensions#wordcount#filetypes += ['pandoc']
let g:pandoc#formatting#mode = 'h'
let g:pandoc#formatting#textwidth = 80

let hostfile= $HOME . '/vimrc-' . hostname()
if filereadable(hostfile)
    exe 'source ' . hostfile
endif

autocmd StdinReadPre * let s:std_in=1
"autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTreeToggle | endif
nnoremap <silent> <Leader>n :silent! NERDTreeFind<CR>:NERDTreeFocus<CR>

if has('nvim')
    " For neovim 0.1.7
    "let $NVIM_TUI_ENABLE_CURSOR_SHAPE = 1
    " For neovim 0.2
    "set guicursor=blah
else
    if $TERM =~ '^xterm\|rxvt'
        " Insert mode
        let &t_SI = "\<Esc>[5 q"
        " Replace mode
        if has("patch-7.4-687")
            let &t_SR = "\<Esc>[3 q"
        endif
        " Normal mode
        let &t_EI = "\<Esc>[2 q"

        " 1 or 0 -> blinking block
        " 2 -> solid block
        " 3 -> blinking underscore
        " 4 -> solid underscore
        " Recent versions of xterm (282 or above) also support
        " 5 -> blinking vertical bar
        " 6 -> solid vertical bar
    endif
endif

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

" nnoremap <silent> <Leader>yy :YcmCompleter GoTo<CR>
" nnoremap <silent> <Leader>yr :YcmCompleter GoToReferences<CR>
" nnoremap <Leader>yd :YcmDiags<CR>
" nnoremap <Leader>yf :YcmCompleter FixIt<CR>
" nnoremap <Leader>y: :YcmCompleter<Space>

au BufWrite *.go :Autoformat

let g:gutentags_project_root_finder = 'projectroot#guess'
let g:gutentags_generate_on_missing = 0
let g:gutentags_generate_on_new = 0
let g:gutentags_modules = ['ctags', 'cscope']
let g:gutentags_cache_dir = $HOME . '/.cache/gutentags'
let g:gutentags_ctags_tagfile = '.vimtags'
set tags=./.vimtags;,.vimtags,./tags;,tags

let g:cmake_export_compile_commands = 1

set cscopetag

let g:ycm_enable_diagnostic_signs=0
" Thanks to http://superuser.com/questions/558876/how-can-i-make-the-sign-column-show-up-all-the-time-even-if-no-signs-have-been-a
"autocmd BufEnter * sign define dummy
"autocmd BufEnter * execute 'sign place 9999 line=1 name=dummy buffer=' . bufnr('')

com -range=% -nargs=1 P exe "<line1>,<line2>!".<q-args> | y | sil u | echom @"
com -range=% Hash <line1>,<line2>P cpp -P -fpreprocessed | tr -d '[:space:]' | md5sum
au FileType cpp com! -buffer -range=% Hash <line1>,<line2>P cpp -P -fpreprocessed | tr -d '[:space:]' | md5sum

nmap <leader>sp :call <SID>SynStack()<CR>
function! <SID>SynStack()
    if !exists("*synstack")
        return
    endif
    echo map(synstack(line('.'), col('.')), 'synIDattr(v:val, "name")')
endfunc

packadd termdebug
