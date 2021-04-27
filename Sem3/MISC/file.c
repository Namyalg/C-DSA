#include<stdio.h>
#include<fcntl.h>

int main(){

    int e = 4;
    printf("%d\n" , e);
    int fd = open("f.txt" , O_RDONLY);
    printf("%d\n" , fd);
    char c[100];
    //file descriptor, the container to store, and the number of characters it needs to read
    int sd = fread(fd, c, 100);
    printf("%s\n" , c);
    int cl = close(fd);
    printf("%d\n" , cl);
    return 0;
}
