#include <bits/stdc++.h>

using namespace std;

//stack has limited space

struct stack{
    int a;
    int top;
};

int push(int arr[],int top, int a, int num){
    if (top >= num) {
        return(20);
    }
    else{
        arr[top++] = a;
        return(top);
    }
    
}
int pop(int arr[], int top){
    if (top <= 0){
        return(-1);
    }
    else{
        return(--top);
    }
}
int main(){
    int arr[20];
    int top = 0;
    int n;
    printf("Enter number less than 20 \n");
    scanf("%d", &n);
    printf("You are going to push elements maintaining the pointer top \n");
    while (top != n) {
        int g;
        printf("Enter the number ");
        scanf("%d", &g);
        top = push(arr, top, g, n);
    }
    for (int i = 0; i < top ; i++){
        printf("%d\n", arr[i]);
        
    }
    printf("You are going to pop elements, enter a number less that length of the array \n");
    int del;
    printf("Enter number of elements to delete ");
    scanf("%d", &del);
    while (del--) {
        top = pop(arr, top);
    }
    for(int i= 0;i < top; i++){
        
        printf("%d\n", arr[i]);

    }
    return 0;

}
