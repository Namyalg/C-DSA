#include<iostream>
#include<bits/stdc++.h>
#define MAX 10

using namespace std;

int qu[MAX];
int front = 0;
int rear = 0;

void enq(int el){
    if(rear >= MAX){
        cout<<"Overflow" <<endl;
    }
    else{
        qu[rear++] = el;
    }
}

void deq(){
    if (front == rear){
        cout<<"Underflow "<<endl;
    }
    else{
        front = front + 1;
    }
}
void display(){
    for(int i = front; i < rear; i++){
        cout<<qu[i]<<" ";
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
                    enq(el);
                    display();
                    break;
                }
            case 2:{
                   
                       deq();
                       display();
                       break;
            }
            default:
                   cout<<"No option "<<endl;

        }

    }
    return 0;
}
