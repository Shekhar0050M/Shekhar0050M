#!/usr/bin/env sh

######################################################################
# @author      : Shekhar Suman (shekhar0050m@gmail.com)
# @file        : script
# @created     : Saturday Aug 07, 2021 08:50:19 IST
#
# @description : 
######################################################################


pkg update && pkg upgrade -y
pkg imstall unstable-repo unzip python proot-distro perl openssh openjdk-17 nodejs neovim neofetch mariadb make man git gdb gdbm fortune exa curl cowsay clang -y
mkdir -p ~/.config/nvim/ 
mkdir -p ~/.termux/ 
cp init.vim ~/.config/nvim/ 
cp cpbooster-config.json ~/ 
cp termux.properties ~/.termux/ 
sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
       https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
echo "Setup complete "
echo "Open neovim by typing nvim/vi and proceed for further installation. "
