#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int d;
    Node* next;
}*head;

Node* getnode(int el){
    Node* temp = new Node;
    temp->next = NULL;
    temp->d = el;
    return temp;
}
void insert(int el){
    Node* temp = getnode(el);
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}
bool dlt(int val){
    Node* move = head;
    if(move->d == val){
        Node* t = move;
        move = move->next;
        head = move;
        delete(t);
        return(true);
    }
    else{
    
    Node* st;
    while(move->next != NULL){
        if (move->next->d == val){
            //cout<<"Yes at "<<count;
            //st = move;
            break;
        }
        move = move -> next;
    }
    Node* rem = move->next;
    Node* ntn = rem->next;
    //cout<<move->d<<" "<<rem->d<<" "<<ntn->d;
    move->next = ntn;
    free(rem);
    return(true);
    }
    return(false);
}
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->d<<" ";
        temp = temp->next;
    }
}
int main(){
    for(int i = 0; i < 7; i++){
        insert(i);
    }
    display();
    cout<<"\n";
    dlt(6);
    cout<<"\n";
    display();
    dlt(2);
    cout<<"\n";
    display();
    dlt(1);
    cout<<"\n";
    display();
    dlt(0);
    cout<<"\n";
    display();
    return 0;
}