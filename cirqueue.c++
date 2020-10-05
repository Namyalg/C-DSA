#include<bits/stdc++.h>
#define MAX 5
using namespace std;

struct queue {
    int rear ;
    int head ;
    int a[10];
}q;

int full(){
    return(q.rear == MAX-1);
}
//In case of the queue u have rear and head, 
//to check if full, if rear == max value, if rear == head set to 0, cause u are at the same point
//increment rear to add, increment head to delete
//FIRST IN FIRST OUT

void enqueue(int el){
    //To begin with if u are at the start, head = rear = 0
    if (q.head == q.rear == -1){
        q.head = q.rear = 0;
        q.a[q.rear] = el;
        rear += 1;
    }
    else if(q.rear == MAX and q.head = 0){
        cout << "Overflow "<<endl;
    }
    else{
        q.a[q.rear] = el;
        rear += 1;
    }
    else{
        cout<<"Overflow";
    }
}

int isEmpty(){
    return(q.head == -1 and q.rear == -1);
}

void dequeue(){
    if (isEmpty()){
        cout<<"Underflow "<<endl;
    }
    else if (q.rear <= q.head) {
        q.rear = q.head = 0;
    }
    else if(q.head == MAX-1){
        q.head = q.rear = 0;
    }
    else{
        q.head += 1;
        if (q.head == q.rear){
            q.head = q.rear = 0;
        }
    }
}
/*void dequeue(){
    if (q.rear == 0 || q.head == q.rear) {
        cout<<"Underflow "<<endl;
    }
    else if (q.rear == q.head){
        q.rear = q.head = 0;
    }
    else {
        q.head = q.head + 1;
    }
}*/

void display(){
    for(int i = q.head; i < q.rear; i++){
        cout << q.a[i] <<endl;
    }
}
int main (){
    q.head = q.rear = 0;
    int ch;
    
    while (1){
    cout << "Enter 1 to add, 2 to delete "<<endl;
    cin>>ch;
    switch(ch) {
        case 1:{
            int el;
            cout<<"Enter an element "<<endl;
            cin>>el;
            enqueue(el);
            display();
            break;
        }
        case 2:{
            dequeue();
            display();
            break;
        }

    }
}
    return 0;
}
