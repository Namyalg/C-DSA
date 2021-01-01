#include<stdio.h>
#include<stdlib.h>
//This is for a doubly linked list
struct Node{
    int v;
    Node* next;
    Node* prev;
};
Node* getNode(int val){
    Node* newn = (Node*)malloc(sizeof(Node));
    newn -> v = val;
    newn -> next = NULL;
    newn -> prev = NULL;
    return newn;
}
void insertfrnt(Node** head, int val){
    Node* newn = getNode(val);
    if ((*head) == NULL){
        (*head) = newn;
    }
    else{
        newn -> next = (*head);
        (*head) -> prev = newn;
        (*head) = newn;
    }
}
int difference(Node* head){
    int max = head -> v;
    int min = head -> v;
    while(head){
        if(head -> v > max){
            max = head -> v;
        }
        if(head -> v < min){
            min = head -> v;
        }
        head = head -> next;
    }
    return(max - min);
}
void display(Node* head){
    while(head){
        printf("%d ", head -> v);
        head = head -> next;
    }
}

void insertbk(Node* h, int val){
    while(h -> next != NULL){
        (h) = (h) -> next;
    }
    Node* newn = getNode(val);
    (h) -> next = newn;
    newn -> prev = h;
}   
int main(){
    Node* head = NULL;
    int c = 1;
    while (c--){
        int x;
        printf("Enter the value : ");
        scanf("%d", &x);
        insertfrnt(&head, x);
    }
    display(head);
    printf("Difference is %d ", difference(head));
    return 0;
}
