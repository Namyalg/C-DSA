#include<stdio.h>
#define MAXSIZE 5

//This is FIFO , last enterted is deleted first
//Thats is once u move to the end, nothing can be done

//This is taken care by circular queue
void enq(int el, int st[MAXSIZE], int* rear){
    if (*rear >= MAXSIZE - 1){
        printf("Overflow \n");
        return;
    }
    else{
        ++(*rear);
        st[*rear] = el;
    }
}

void deq(int *rear, int* front, int st[MAXSIZE]){
    int idx = *front;
    if (idx > *rear){
        printf("Underflow \n");
        return;
    }
    else{
        ++(*front);
        printf("Deleted is  %d \n", st[idx]);
    }
}

void show(int* front, int* rear, int st[MAXSIZE]){
    printf("\n");
    for(int i = *front; i <= *rear; i++){
        printf("%d ", st[i]);
    }
    printf("\n");
}

int main(){ 
    int ch;
    int st[MAXSIZE] = {0};
    int front = 0;
    int rear = -1;
    while (1){
        printf("Enter choice, 1 to add, 2 to dlt \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int el;
                printf("Enter element \n");
                scanf("%d", &el);
                enq(el, st, &rear);
                show(&front, &rear, st);
                break;
            }
            case 2:{
                deq(&rear, &front, st);
                show(&front, &rear, st);
                break;
            }
        }
    }
    return 0;
}