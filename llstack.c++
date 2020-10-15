#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* create(int value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    return temp;
    
}

int main(){
    Node* head = NULL;
    Node* make;
    for(int i = 0;i < 5 ; i++){
        make = create(i);
        if (head == NULL){
            head = make;
        }
        else{
            make->next = head;
            head = make;
        }
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
    
}
