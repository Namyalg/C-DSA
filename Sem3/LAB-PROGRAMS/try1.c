#include<stdio.h>
#include<stdlib.h>

struct Node{
    char* msg;
    Node* next;
}*head = NULL;
//need to change the integer to string
//Add to the end and delete from the front

Node* getnode(char msg[]){
    Node* newn = (Node*)malloc(1*sizeof(Node*));
    newn -> msg = msg;
    newn -> next = newn;
    return newn;
}

void enqueue(char msg[]){
    Node* newn = getnode(msg);
    if(head == NULL){
        head = newn;
    }
    else{
        newn -> next = head -> next;
        head -> next = newn;
        head = newn;
    }
}

void dequeue(){
    if(head == NULL){
        printf("Message Queue is Empty!\n");
    }
    else if(head -> next == head){
        printf("The message that will be deleted is ");
        printf("%s\n", head -> msg);
        free(head);
        head = NULL;
    }
    else{
        Node* start = head -> next;
         printf("The message that will be deleted is ");
         printf("%s\n",  start -> msg);
         head -> next = start -> next;
        free(start);
        start = NULL;
    }
}

void display(){
    if(head == NULL){
        printf("Message queue is empty\n");
    }
    else{
        Node* start = head -> next;
   
            printf("The messages in the queue are\n");
            while(start != head){
                printf("%s ", start -> msg);
                start = start -> next;
            }
            printf("%s\n" , start -> msg);
        
    }
}
int main(){
    int choice;
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Sender\n2.Receiver (Delete a message)\n3. Receiver (View a message)\n");
    while(1){
        printf("****************************************");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                char message[1000];
                printf("Enter the message : ");
                scanf("%s", message);
                enqueue(message);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
            default:
            printf("Wrong Option! \n");
        }
    }
    return(0);
}