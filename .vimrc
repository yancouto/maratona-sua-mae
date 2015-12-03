set ai si noet ts=4 sw=4 sta sm nu rnu
inoremap {<CR> {<CR>}<Esc>O
inoremap <NL> <ESC>o
nnoremap <NL> o
inoremap <C-up> <C-o>:m-2<CR>
inoremap <C-down> <C-o>:m+1<CR>
nnoremap <C-up> :m-2<CR>
nnoremap <C-down> :m+1<CR>
vnoremap <C-up> :m-2<CR>gv
vnoremap <C-down> :m'>+1<CR>gv
colors evening
syntax on
"highlight Normal ctermbg=NONE "No background
"highlight nonText ctermbg=NONE
