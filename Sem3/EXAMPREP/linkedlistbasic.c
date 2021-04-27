#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    Node* next;
};

Node* getnode(int el){
    Node* temp = (Node*)(malloc(sizeof(Node)));
    temp -> val = el;
    temp -> next = NULL;
    return temp;
}

void insertfrnt(int val, Node** head){
    Node* temp = getnode(val);
    if (*head == NULL){
        *head = temp;
        return;
    }
    else{
        temp -> next = *head;
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
        printf("Deleted is %d \n", tb -> val);
        free(tb);
        t -> next = NULL;
    }
}

// void removenode(Node** head, int val){
//     if((*head) == NULL){
//         return;
//     }
//     else if((*head) -> next == NULL && (*head) -> val == val){
//         free((*head));
//         (*head) = NULL;
//         return;
//     }
//     else{
//         Node* t = *head;
//         Node* temp = *head;
//         Node* prev = *head;
//         while(t != NULL && t -> next != NULL){
//             if (t -> next != NULL){
//                 if (t -> next -> val == val){
//                     Node* g = t -> next;
//                     if(g -> next != NULL){
//                         t -> next = g -> next;
//                     }
//                 }
//             }
//             prev = t;
//             t = t -> next;
//         }
//         //printf("\n Previous value is %d\n" , prev -> val);
//         if(prev -> next-> next != NULL && prev -> next-> next -> val == val);
//             prev -> next = NULL;
//     }
//     //    printf("\n%d" , t -> next -> val);
// }

void removenode(Node** head, int val){
        Node* p = *head;
        while(p != NULL && p -> next != NULL){
            if(p ->next -> val == val){
                
                    p -> next = p -> next -> next;
            }
            else{
                p = p -> next;
            }
        }
        if((*head) -> val == val){
            *head = (*head) -> next;
        }
    }


int getlen(Node* head){
    int l = 0;
    while(head != NULL){
        head = head -> next;
        l += 1;
    }
    return l;
}

void dltalternate(Node* head){
    int len = getlen(head);
    Node* temp = head -> next;
    Node* h = head;

    //slightly different for odd and even as the access will be different for both

    if (len & 1){
        while(temp != NULL && temp -> next-> next != NULL){
            temp = h -> next;
            h -> next = temp -> next;
            h = h -> next;
        }
    }
    else{
        while(temp != NULL && temp -> next != NULL){
            temp = h -> next;
            h -> next = temp -> next;
            h = h -> next;
        }
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

        *head = (*head) -> next;
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
                insrtbk(el, &head);
                display(head);
                break;
            }
            case 2:{
                 dltbk(&head);
                 display(head);
                 break;
            }
            case 3:{
                dltalternate(head);
                display(head);
                break;
            }
            case 4:{
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