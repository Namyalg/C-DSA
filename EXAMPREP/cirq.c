#include<stdio.h>
#define MAXSIZE 5

//This is LIFO , last enterted is deleted first

void enq(int el, int st[MAXSIZE], int* rear, int * front){
    if (*front == -1 && *rear == -1){
        *front = 0;
        *rear = 0;
        st[*rear] = el;
    }
    else if(*rear == MAXSIZE - 1 && *front == 0 || (*rear + 1 == *front)){
        printf("Overflow \n");
        return;
    }
    else{
        *rear = (*rear + 1) % MAXSIZE;
        st[*rear] = el;
    }
}

void deq(int *rear, int* front, int st[MAXSIZE]){
    int idx = *front;
    if((*front == -1 && *rear == -1)){
        printf("Underflow \n");
        return ;
    }
    if (*front == *rear){
        printf("Deleted is  %d \n", st[idx]);
        st[idx] = 0;
        *front = -1;
        *rear = -1;
        return;
    }
    else{
        *front = (*front + 1) % MAXSIZE;
        printf("Deleted is  %d \n", st[idx]);
        st[idx] = 0;
    }
}

void show(int* front, int* rear, int st[MAXSIZE]){
    printf("\n");
    for(int i = 0; i < MAXSIZE; i++){
        printf("%d ", st[i]);
    }
    printf("\n");
}

//This is for the specifics,m write in the assumption for better understanding it is replced with a0
// void show(int* front, int* rear, int st[MAXSIZE]){
//     printf("\n");
//     if(*rear > *front){
//         for(int i = *front; i <= *rear; i++){
//             printf("%d ", st[i]);
//         }
//     }
//     else{
//         for(int i = *front; i < MAXSIZE; i++){
//             printf("%d ", st[i]);
//         }
//         for(int i = 0; i < *rear; i++){
//             printf("%d ", st[i]);
//         }
//     }
//     printf("\n");
// }

int main(){ 
    int ch;
    int st[MAXSIZE] = {0};
    int front = -1;
    int rear = -1;
    while (1){
        printf("Enter choice, 1 to add, 2 to dlt \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int el;
                printf("Enter element \n");
                scanf("%d", &el);
                enq(el, st, &rear, &front);
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