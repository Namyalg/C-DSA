#include<stdio.h>
#include<stdlib.h>
//to take control of the first node in circular that means u need to do head -> next
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
Node* getnode(int val){
    Node* temp = (Node*)malloc(1*sizeof(Node));
    temp->data = val;
    temp->next = temp;
    return(temp);
}
void dltfromend(){
    if(head == NULL){
     printf("%s ", "Empty");
    }
    else if(head == head -> next){
        free(head);
        head = NULL;
    }
    else{
        //need to move in a loop
        Node* move = head -> next;
        //one node before
        //while next->next will go one before before
        while(move -> next!= head){
            move = move -> next;
        }
        move -> next = head -> next;
        free(head);
        head = move;
    }
}
void dltfromstart(){
    if(head == NULL){
        printf("%s ", "Empty");
    }
    else if(head == head -> next){
        free(head);
        head = NULL;
    }
    else{
        Node* temp = head -> next;
        head -> next = temp -> next;
        free(temp);
    }
}
void insert(int val){
    Node* temp = getnode(val);
    if (head == NULL){
        head = temp;
    }
    else{
        //so the last  node is always pointed to by head
        temp -> next = head -> next;
        head -> next = temp;
        head = temp;
    }
}
void display(){
    Node* move = head -> next;
    while(move != head){
        printf("%d ", move->data);
        move = move -> next;
    }
    printf("%d", move -> data);
}

int main(){
   
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();
    return 0;
}