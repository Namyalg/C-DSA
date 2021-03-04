#include<stdio.h>
#include<stdlib.h>
struct Node{
    int v;
    Node* next;
};
Node* getNode(int val){
    Node* newn = (Node*)malloc(sizeof(Node));
    newn -> v = val;
    newn -> next = NULL;
    return newn;
}
void insertfrnt(Node** head, int val){
    Node* newn = getNode(val);
    if ((*head) == NULL){
        (*head) = newn;
    }
    else{
        newn -> next = (*head);
        (*head) = newn;
    }
}
void deletedup(Node* head){
    if (head == NULL || head -> next == NULL){
        return;
    }
    if (head -> v == head -> next -> v && head -> next -> next == NULL){
        Node* temp = head -> next;
        free(temp);
        head -> next = NULL;
        return;
    }
    Node* p1 = head;
    Node* p2 = head -> next;
    while(p2 != NULL){
        if (p1 -> v != p2 -> v){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        else{
            printf("p1 at %d", p1 -> v);
            printf("p2 at %d", p2 -> v);
            p1 -> next = p2 -> next;
            p2 -> next = p1 -> next;
            printf("p1 at %d", p1 -> v);
            printf("p2 at %d", p2 -> v);
        }
    }

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
}
int main(){
    Node* head = NULL;
    int c = 5;
    while (c--){
        int x;
        printf("Enter the value : ");
        scanf("%d", &x);
        insertfrnt(&head, x);
    }
    deletedup(head);
    display(head);
    return 0;
}