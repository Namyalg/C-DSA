#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Needed file name");
        return 0;
    }
    else{
        int readb = 0;
        int fd = open(argv[1], O_RDWR | O_CREAT);
        int fd1 = open("file.txt",O_RDWR);
        char buffer[2000];
        char message[2000] = "Some great stuff";
        
        readb = read(fd, buffer, 1000);
        
        //write from one file to another
        write(fd1, buffer, strlen(buffer));
        printf("Number of bytes read were %d \n", readb);
        printf("%s", buffer);
        close(fd);
        close(fd1);
    }
    return 0;
}