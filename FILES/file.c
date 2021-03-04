#include<stdio.h>
#include<fcntl.h>
//fcntl is not supported in WSL I think, thats why there is this sort of problemsss
int main(){
    int fd = open("blew.txt", O_RDONLY);
    printf("File descriptor reads, %d ", fd);
    int r;
    char buf[1000];
    r = read(fd, buf, 30);
    printf("The read call returns %d and the contents are %s ", r, buf);
    close(fd);
    return 0;
}