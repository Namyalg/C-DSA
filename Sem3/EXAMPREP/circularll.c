// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int val;
//     Node* next;
// };

// Node* getnode(int el){
//     Node* temp = (Node*)(malloc(sizeof(Node)));
//     temp -> val = el;
//     temp -> next = temp;
//     return temp;
// }

// void insertbk(int val, Node** head){
//     Node* temp = getnode(val);
//     if((*head) == NULL){
//         (*head) = temp;
//     }
//     else{
//         temp -> next = (*head) -> next;
//         (*head) -> next = temp;
//         (*head) = temp;
//     }
// }

// void dlt(Node** head){
//     if((*head) -> next == (*head)){
//         (*head) = NULL;
//         return ;
//     }
//     else{
//         Node* t  = (*head) -> next;
//         if(t == (*head)){
//             free((*head));
//             (*head) = NULL;
//             return;
//         }
//         while(t -> next != (*head)){
//             t = t -> next;
//         }
//          t -> next = (*head) -> next;
//         free((*head));
//         (*head) = t;

        
//         //printf("At the node %d", t -> val);
//     }
// }


// void display(Node* head){
//     Node* t = head -> next;
//     while(t != head){
//         printf("%d ", t -> val);
//         t = t -> next;
//     }
//     printf("%d ", head -> val);
//     printf("\n");
// }
// int main(){
//     int ch;
//     Node* head = NULL;
//     while (1){
//         printf("Enter choice, 1 to add, 2 to dlt \n");
//         scanf("%d", &ch);
//         switch(ch){
//             case 1:{
//                 int el;
//                 printf("Enter element \n");
//                 scanf("%d", &el);
//                 insertbk(el, &head);
//                 display(head);
//                 break;
//             }
//              case 2:{
//                   dlt(&head);
//                   display(head);
//                   break;
//              }
//             // case 3:{
//             //     dltalternate(head);
//             //     display(head);
//             //     break;
//             // }
//             // case 4:{
//             //     int v;
//             //     printf("Enter val to delete \n");
//             //     scanf("%d" , &v);
//             //     removenode(&head, v);
//             //     display(head);
//             //     break;
//             // }
//         }
//     }
//     return 0;
// }




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
   int ch;
    while (1){
        printf("Enter choice, 1 to add, 2 to dlt \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int el;
                printf("Enter element \n");
                scanf("%d", &el);
                insert(el);
                display();
                break;
            }
             case 2:{
                  dltfromend();
                  display();
                  break;
             }
        }
    }
    return 0;
}