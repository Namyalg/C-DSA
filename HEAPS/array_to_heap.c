#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
int heap[MAX_SIZE + 1];

//counter is set to 1, as the first element is set to INT_MAX
int counter = 1;

void maxHeapify(){
    int k, v;
    int h, fc;
    for(int i = counter / 2; i > 0; i--){
        k = i;
        v = heap[i];
        h = 0;
        while((!h) && 2 * k <= counter){
            fc = 2 * k;
            if(fc < counter){
                if (heap[fc] < heap[fc + 1]){
                    fc += 1;
                }
            }
            if(v >= heap[fc]){
                h = 1;
            }
            else{
                heap[k] = heap[fc];
                k = fc;
            }
        }
        heap[k] = v;
    }
}

void display(){
    if(counter == 1){
        printf("Empty priority queue \n");
    }
    else{
        printf("Contents are : ");
        for(int i = 1; i < counter; i++){
            printf("%d ", heap[i]);
        }
    }
}
void insert(int el){
    if(counter > MAX_SIZE){
        printf("Overflow !");
    }
    else{
        heap[++counter] = el;
        maxHeapify();
    }
}
void delet(){
    if(counter == 1){
        printf("Underflow !");
    }
    else{
        heap[1] = heap[counter];
        display();
        counter = counter - 1;
        maxHeapify();
    }
}

int main(){
    int ch;
    //to ensure ease of access the index 0 is set to INT_MAX
    heap[0] = __INT_MAX__;
    while(1){
        printf("\n 1.Insert \n 2.Delete \n 3.Display \n\n");
        printf("Enter the option : ");
        scanf("%d", &ch);
        switch(ch){5
        
            case 1:{
                int el;
                printf("Enter element : ");
                scanf("%d", &el);
                insert(el);
                printf("Counter is %d \n", counter);
                break;
            }
            case 2:{
                delet();
                break;
            }
            case 3:{
                display();
                break;
            }
            default :
                printf("Wrong option !");
        }
    }
    return 0;
}
