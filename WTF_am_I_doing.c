#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include<unistd.h>
#include <string.h>
// float rdm()
// {
//     int temp = rand() % 100;
//     float rdm = (float)temp / 100.0;
//     return rdm;
// }

void writeSlow(char *str)
{
    for (int i = 0; i < strlen(str); ++i) {
        usleep(100000);
        write(1, str + i, 1);
    }
}

int main (int ac, char **av)
{
    srand(time(NULL));
    system("clear");
    writeSlow("Today is your last day");
    sleep(3);
    system("setxkbmap ru");

    system("xrandr -o inverted");
    while (1) {
        system("xrandr --output eDP-1 --gamma 0.1:1:0.1");
        system("xrandr --output eDP-1 --gamma 0.1:0.1:1");
        system("xrandr --output eDP-1 --gamma 1:0.1:0.1");
        system("xrandr --output eDP-1 --gamma 0.1:1:1");
        system("xrandr --output eDP-1 --gamma 1:1:0.1");
        system("xfce4-terminal");
    }

    return 0;
}