#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

int count = 0;
struct Node{
    char msg[1000];
    Node* next;
}*head = NULL;
//need to change the integer to string
//Add to the end and delete from the front
Node* getnode(char msg[1000]){
    Node* newn = (Node*)malloc(1*sizeof(Node*));
    strcpy(newn -> msg , msg);
    newn -> next = newn;
    return newn;
}
void enqueue(char msg[1000]){
    if(count >= MAX){
        printf("Queue Overflow!\n");
    }
    else{
        Node* newn = getnode(msg);
        if(head == NULL){
            head = newn;
            count += 1;
        }
        else{
            newn -> next = head -> next;
            head -> next = newn;
            head = newn;
            count += 1;
        }
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
        count = count - 1;
        head = NULL;
    }
    else{
        Node* start = head -> next;
         printf("The message that will be deleted is ");
         printf("%s\n",  start -> msg);
         head -> next = start -> next;
        free(start);
        count = count - 1;
        start = NULL;
    }
}

void display(){
    if(head == NULL){
        printf("Message queue is empty\n");
    }
    else{
        Node* start = head -> next;
         if(start -> next == head){
            printf("The message queue contains : ");
            printf("%s\n", start->msg);
             printf("%s\n", start->next -> msg);
            return;
        }
        else{
            printf("The message queue contains : ");
            while(start != head){
                printf("%s\n", start -> msg);
                start = start -> next;
            }
            printf("%s\n" , start -> msg);
        }
    }
}
int main(){
    int choice;
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Sender\n2.Receiver (Delete a message)\n3.Receiver (View a message)\n");
    while(1){
        printf("****************************************");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                char message[1000];
                printf("Enter the message : ");
                //fgets(message, 1000, stdin);
                gets("%s", message);
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