#include<iostream>
#include<bits/stdc++.h>
#define MAX 10

using namespace std;

int stack[MAX];
int top = 0;

void push(int el){
    if(top >= MAX){
        cout<<"Overflow" <<endl;
    }
    else{
        stack[top++] = el;
    }
}

void pop(){
    if (top == 0){
        cout<<"Underflow "<<endl;
    }
    else{
        top = top - 1;
    }
}
void display(){
    for(int i = 0; i < top; i++){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int ch;
    while(true){
        cout<<"Enter 1 to add, 2 to delete "<<endl;
        cin>>ch;
        switch(ch){
            case 1:{
                    int el;
                    cout<<"Enter el "<<endl;
                    cin>>el;
                    push(el);
                    display();
                    break;
                }
            case 2:{
                   
                       pop();
                       display();
                       break;
            }
            default:
                   cout<<"No option "<<endl;

        }

    }
    return 0;
}
