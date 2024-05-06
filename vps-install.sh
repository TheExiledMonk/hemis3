#! /bin/bash
echo "Installing unzip"
sudo apt install unzip -y
echo "unzip installed"

echo "Fetching latest Hemis version"
wget --quiet https://github.com/Hemis-Blockchain/Hemis/releases/latest/download/Hemis-Linux.zip && sudo unzip Hemis-Linux.zip -d /usr/local/bin
wget --quiet https://github.com/Hemis-Blockchain/Hemis/releases/latest/download/Hemis-params.zip && unzip Hemis-params.zip -d ~/.Hemis-params
echo "Hemis succesfully installed and added daemon=1 to config"
mkdir -p ~/.Hemis
echo "daemon=1" > ~/.Hemis/Hemis.conf 
echo "Cleanup excess files"
rm Hemis-Linux.zip && rm Hemis-params.zip
echo "Running Hemisd"
Hemisd
exit
