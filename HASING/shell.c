#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int   main(){
        char *shell = getenv("SHELL");
        execl(shell, NULL, NULL);
        printf("going\n");
        perror("execl() failed");
        return 0;
}