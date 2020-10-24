#include<stdio.h>

int main(void){
    printf("Hello");
    asm:
    {
        mov eax,20;
    }
    return(0);
}