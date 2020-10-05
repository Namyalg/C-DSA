#include<iostream>
#include<bits/stdc++.h>
#define MAX 5

using namespace std;

struct st{
    int rear;
    int head;
    int a[MAX];
}q;

int isempty(){
    if (q.head == -1)
        return(1);
    return(0);
}

void display(){
    if (isempty()) {
        cout<<"Empty "<<endl;
    }
    else
    {
        for(int i = 0; i < MAX; i++) {
            cout << q.a[i] <<" " ;
        }
       /* for(int i= q.head;i < q.rear ;i++) {
            cout << q.a[i] << " ";
        }
        for(int i= 0;i < q.head ;i++) {
            cout << q.a[i] << " ";
        }*/
        cout<<endl;
    }
}
void enqueue(int el){
    if (q.head == -1 and q.rear == -1) {
        q.rear += 1;
        q.head += 1;
        q.a[q.rear++] = el;
        //q.rear += 1;
    }
    else if(q.rear == MAX && q.head == 0){
        cout<<"Overflow "<<endl; 
    }
    else if(q.rear == q.head) {
        cout << "Overflow "<<endl;
        q.head = q.rear = 0;
    }
    //here rear maybe behind front
    else if(q.rear == MAX and q.head != 0) {
        q.rear = 0;
        q.a[q.rear] = el;
        q.rear += 1;
    }
    else{
        q.a[q.rear++] = el;
    }

}
void dequeue(){
    if (q.head == -1 and q.rear == -1) {
        cout << "Underflow "<<endl;
    }
    else if(q.head >= MAX) {
        q.head = q.rear = 0;
    }
    else {
        q.a[q.head] = 0;
        q.head += 1;
    }
}

int main(){
    q.rear = q.head = -1;
    q.a[MAX] = {0};
    int ch;
    while (1) {
        cout << "Enter choice 1 to add, 2 to delete"<<endl;
        cin>>ch;
        switch(ch) {
            case 1: {
                int ele;
                cout << "enter elemenent " <<endl;
                cin>>ele;
                enqueue(ele);
                display();
                break;
            }
            case 2: {
                dequeue();
                display();
                break;
            }

        }

    }
    return 0;
}
