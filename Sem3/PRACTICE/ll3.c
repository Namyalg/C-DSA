#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    Node* next;
};

Node* getnode(int val){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> val = val;
    newn -> next = newn;
    return newn;
}
//u are adding to the front of the list
//here u consider that the head is the last pointer in the list

void insert(Node** head, int val){
    Node* newn = getnode(val);
    if((*head) == NULL){
        (*head) = newn;
    }
    else{
        newn -> next = (*head) -> next;
        (*head) -> next = newn;
        (*head) = newn;
    }
}
void display(Node* head){
    Node* t = head -> next;
    while(t != head){
        printf("%d ", t -> val);
        t = t -> next;
    }
    printf("%d ", t -> val);
}
//in this circular linked
int main(){
    int el;
    Node* head = NULL;
    Node* temp = NULL;
    int choice;
    do{
        printf("Enter 1 to add, 2 to delete from front :  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element ");
            scanf("%d", &el);
            insert(&head, el);
            display(head);
            printf("\n");
            break;
        /*case 2:
            delete(&head);
            display(head);
            printf("\n");
            break;*/
        
        default:
            break;
        }
      
    }while(1);
    return 0;
}