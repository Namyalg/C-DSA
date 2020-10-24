#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top = 0;
int temp[MAX];
int y;

void push(int val){
    if(head > MAX){
        printf("OverFlow\n");
    }
    else{
        stack[top++] = val;
    }
}

void pop(){
    if(top < 0){
        printf("Underflow\n");
    }
    else{
        top--;
    }
}   

void display(){
    printf("Contents are : \n");
    for(int i = 0; i < top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void third_from_top(){
    
}