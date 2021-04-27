#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    Node* next;
    Node* prev;
};

Node* getnode(int el){
    Node* temp = (Node*)(malloc(sizeof(Node)));
    temp -> val = el;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void removenode(Node** head, int val){
        Node* p = *head;
        while(p != NULL && p -> next != NULL){
            if(p ->next -> val == val && p -> next -> next != NULL){
                    if(p -> next -> next == NULL){
                        p -> next = NULL;
                    }
                    else{
                        p -> next = p -> next -> next;
                        p -> next -> next -> prev = p;
                    }
            }
            else{
                p = p -> next;
            }
        }
        if((*head) -> val == val){
            (*head) -> prev = NULL;
            *head = (*head) -> next;
        }
}

void insertfrnt(int val, Node** head){
    Node* temp = getnode(val);
    if (*head == NULL){
        *head = temp;
        return;
    }
    else{
        temp -> next = *head;
        (*head) -> prev = temp;
        *head = temp;
    }
}

void dltbk(Node** head){
    if (*head == NULL){
        printf("Underflow \n");
        return;
    }
    else if((*head) -> next == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        Node* t = *head;
        
        //if there are 10 -> 12 -> 13 -> 112

        //then to delete 112 u need to be at 13, so 13 -> next -> next = NULL
        //this is what u have to look for

        while (t -> next -> next != NULL){
            t = t -> next;
        }
        Node* tb = t -> next;
        tb -> prev = NULL;
        printf("Deleted is %d \n", tb -> val);
        free(tb);
        t -> next = NULL;
    }
}
void insrtbk(int val, Node** head){
  Node* t = getnode(val);
    if (*head == NULL){
        *head = t;
        return;
    }
    else{
        //Takes O(1) to find the actual spot of insertion

        //if u have 12 -> 13 -> 14, then to insert 16
        //u need to get to 14, where 14 -> next = NULL
        //so accordingly u have to find node 14 and set its next to 16
        Node* temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        //Find the last node that can be deleted
        t -> prev = temp;
        temp -> next = t;
    }

}


void dltfrnt(Node** head){
    if(*head == NULL){
        printf("Underflow \n");
    }
    else{
        Node* temp = *head;
        printf("Deleted is %d \n", temp -> val);
        
        //brackets around this as it is (*head) 
        if(temp -> next != NULL){
        *head = (*head) -> next;
        (*head) -> prev = NULL;
        }
        else{
            *head = NULL;
        }
        free(temp);
    }
}

void display(Node* head){
    while(head != NULL){
        printf("%d ", head -> val);
        head = head -> next;
    }
    printf("\n");
}


int main(){
    int ch;
    Node* head = NULL;
    while (1){
        printf("Enter choice, 1 to add, 2 to dlt \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int el;
                printf("Enter element \n");
                scanf("%d", &el);
                insertfrnt(el, &head);
                display(head);
                break;
            }
            case 2:{
                 dltbk(&head);
                 display(head);
                 break;
            }
             case 3:{
                int v;
                printf("Enter val to delete \n");
                scanf("%d" , &v);
                removenode(&head, v);
                display(head);
                break;
            }
        }
    }
    return 0;
}