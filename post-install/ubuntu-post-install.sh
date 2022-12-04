#!/bin/bash

# update system and install software
sudo apt -y update
sudo apt -y dist-upgrade
sudo apt -y install apt-transport-https htop mc git build-essential cmake gdb vim
sudo apt -y install pandoc texlive-base texlive-latex-extra texlive-fonts-recommended texlive-fonts-extra texlive-pictures texlive-lang-italian
sudo apt -y autoremove
sudo apt -y clean

sudo snap install sublime-text --classic
sudo snap install sublime-merge --classic
sudo snap install clion --classic

# osx theme
git clone https://github.com/vinceliuice/WhiteSur-icon-theme.git
git clone https://github.com/vinceliuice/WhiteSur-wallpapers.git
git clone https://github.com/vinceliuice/WhiteSur-gtk-theme.git
./WhiteSur-wallpapers/install-wallpapers.sh
./WhiteSur-icon-theme/install.sh
./WhiteSur-gtk-theme/install.sh
rm -rf WhiteSur*

# vim theme
cp -r extra/.vim* "$HOME"

exit 0
