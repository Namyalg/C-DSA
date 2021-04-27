#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    Node* next;
};

Node* getnode(int val){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> val = val;
    newn -> next = NULL;
    return newn;
}

//this is a different implementation with Node **head
//IT IS PASSED BY REFERENCE AND THE VALUE CHANGES BY REFERENCE

void insertfrnt(Node** head, int val){
    Node* newn = getnode(val);
    if((*head) == NULL){
        (*head) = newn;
    }
    else{
        newn -> next = (*head);
        (*head) = newn;
    }
}

void insertend(Node** head, Node** temp, int val){
    Node* newn = getnode(val);
    if(*head == NULL){
        *head = newn;
        *temp = newn;
    }
    else{
        (*temp) -> next = newn;
        *temp = newn;
    }
}
//reversing a linked list
//passed by reference so u dont have to return and stuff
void deleteend(Node** temp){
    Node* st = (*temp);
    if(st == NULL){
        printf("Empty ");
       
    }
    else if(st -> next == NULL){
        free(st);
        st = NULL;
      
    }
    else{
        while(st -> next -> next != NULL){
            st = st -> next;
        }
        Node* last = st -> next;
        st -> next = NULL;
        free(last);
    }
}
void deletefrnt(Node** head){
    if((*head) == NULL){
        printf("Empty : (");
        return;
    }
    Node* temp = (*head);
    (*head) = (*head) -> next;
    free(temp);
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* nxt = NULL;
    Node* curr = head;
    while(curr != NULL){
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    return head;

}
void display(Node* head){
    Node* temp = head;
    if(temp == NULL){
        printf("Empty :(");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
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
            insertend(&head, &temp, el);
            display(head);
            printf("\n");
            break;
        case 2:
            deleteend(&head);
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