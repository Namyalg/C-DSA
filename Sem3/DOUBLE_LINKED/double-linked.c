#include<stdio.h>
#include<stdlib.h>

//(q -> next)->next means one before the end, u are ending at
//This points to the last poninter
struct Node {
    Node* prev;
    int data;
    Node* next;
};
//Additional memory 
//But can move backward also
//constraint is ONLY one pointer
//
Node* head = NULL;
Node* tail = NULL;
Node* m;
Node* getnode(int val){
    Node* temp = (Node*)malloc(1*sizeof(Node));
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;
    return temp;

}
void insertfrnt(int val){
    Node* temp = getnode(val);
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
        //head->next = temp;
        //temp->prev = head;
        //head = temp;

    }
}

void insertend_with1ptr(int val){
    Node* temp = getnode(val);
    if(head == NULL){
        head = temp;
        m = temp;
    }
    else{
        temp->prev = head;
        head->next = temp;
        head = temp;
    }
}

void insertend_with2ptr(int val){
    Node* temp = getnode(val);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void dlt_with_1ptr(){
    if(head == NULL){
        printf("%s\n", "Empty ");
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node* traverse = m;
        printf("%d" , traverse->data);
        /*while(traverse->next != NULL){
            traverse = traverse -> next;
        }
        //Node* l = traverse->next;
        traverse->next = NULL;
        free(traverse->next);
        //l -> prev = NULL;
        //free(l);*/
    }
}

void dltfront(){
    if(head == NULL){
        printf("%s", "Empty ");
        exit(0);
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
        //prevent a dangling pointer
    }
    else{
        Node* t = head;
        head = head -> next;
        head->prev = NULL;
        free(t);
    }
}

void dltinend(){
    if(head == NULL){
        printf("%s" , "Empty");
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node* move = head;
        while((move -> next)->next != NULL){
            move = move -> next;
        }
        Node* last = move -> next;
        move -> next = NULL;
        free(last);

    }
}
void dltend(){
    if(head == NULL){
        printf("%s", "Empty ");
        exit(0);
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node* temp = head;
        while((temp->next)->next != NULL){
            temp = temp -> next;
        }
        Node* last = tail;
        last->prev = NULL;
        temp->next = NULL;
        tail = temp;
        free(last);
    }

}
void display(){
    Node* move = m;
    printf("%s\n", "Contents");
    while(move != NULL){
        printf("%d " , move->data);
        move = move -> next;
    }
    printf("\n");
}
int main(){
    int ch;
    while(true){
        printf("Enter 1 to add, 2 to delete \n");
        scanf("%d" , &ch);
        switch(ch){
            case 1:{
                    int el;
                    printf("Enter element \n");
                    scanf("%d" , &el);
                    insertfrnt(el);
                    //insertend_with2ptr(el);
                    display();
                    break;
                }
            case 2:{
                   
                       //dltfront();
                       //dlt_with_1ptr();
                       dltinend();
                       display();
                       break;
            }
            default:
                   printf("No option \n");

        }

    }
    return 0;
}

