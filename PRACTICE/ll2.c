#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    Node* prev;
    Node* next;
};

Node* getnode(int val){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> val = val;
    newn -> next = NULL;
    newn -> prev = NULL;
    return newn;
}

void insertfrnt(Node** head, int val){
    Node* newn = getnode(val);
    if((*head) == NULL){
        (*head) = newn;
    }
    else{
        newn -> next = (*head);
        (*head) -> prev = newn;
        (*head) = newn;
    }
}
void display(Node* head){
    while(head != NULL){
        printf("%d ", head -> val);
        head = head -> next;
    }
}
void deletefrnt(Node** head){
    Node* temp = (*head);
    (*head) = (*head) -> next;
    (*head) -> prev = NULL;
    free(temp);
    temp = NULL;
}

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
            insertfrnt(&head, el);
            display(head);
            printf("\n");
            break;
        case 2:
            deletefrnt(&head);
            display(head);
            printf("\n");
            break;
        default:
            break;
        }
      
    }while(1);
    //head = reverse(head);   
    //display(head);
    return 0;
}