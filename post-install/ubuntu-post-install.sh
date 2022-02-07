#!/bin/bash

sudo apt -y update
sudo apt -y dist-upgrade
sudo apt -y install apt-transport-https
sudo apt -y install gnome-session gdm3 gnome-tweak-tool numix-icon-theme-circle
sudo apt -y install htop mc git build-essential cmake gdb vim
sudo apt -y install pandoc texlive-base texlive-latex-extra texlive-fonts-recommended texlive-fonts-extra texlive-pictures texlive-lang-italian
sudo apt -y autoremove
sudo apt -y clean

sudo snap install sublime-text --classic
sudo snap install clion --classic

cp -r extra/.vim* "$HOME"

exit 0
