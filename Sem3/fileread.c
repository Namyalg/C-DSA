#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int fd = open("content.txt", O_RDONLY);
    char buffer[1000];
    char *cf;
    if(fd > 0){
        read(fd, buffer, 1000);
        int c = 0;
        for(int i = 0; buffer[i] != '\0'; i++){
            c += 1;
        }
        printf("\nchar count is %d", c);
    }
    return 0;
}
