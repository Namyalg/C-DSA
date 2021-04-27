#include<stdio.h>
#define MAXSIZE 5

//This is LIFO , last enterted is deleted first

void push(int el, int st[MAXSIZE], int* top){
    if (*top >= MAXSIZE - 1){
        printf("Overflow \n");
        return;
    }
    else{
        ++(*top);
        st[*top] = el;
    }
}
void pop(int *top, int st[MAXSIZE]){
    int idx = *top;
    if (idx < 0){
        printf("Underflow \n");
        return;
    }
    else{
        --(*top);
        printf("Deleted is  %d \n", st[idx]);
    }
}

void show(int* top, int st[MAXSIZE]){
    printf("\n");
    for(int i = 0; i <= *top; i++){
        printf("%d ", st[i]);
    }
    printf("\n");
}

int main(){
    int ch;
    int st[MAXSIZE] = {0};
    int top = -1;
    while (1){
        printf("Enter choice, 1 to add, 2 to dlt \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int el;
                printf("Enter element \n");
                scanf("%d", &el);
                push(el, st, &top);
                show(&top, st);
                break;
            }
            case 2:{
                pop(&top, st);
                show(&top, st);
                break;
            }
        }
    }
    return 0;
}