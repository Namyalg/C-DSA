#include<stdio.h>
#include <cstdlib>
//dynamically allocate
//eg : inserting a new element in between if increasing
//but here random access is not possible as the previous node has a link to the next one
//always need to start from the first node

//atleast 2 parts
//
//********************
//* data  * pointer  *
//********************
struct node{
    int n;
    //char name[10];
    struct node* next;
    //pointer to struct, so the type has to be the same
};
//size of node = size of all + size of pointer
//2 bytes for the pointer(16 bits)

//mainly when u need to store but donno how many

void insert(int value, node* head){

    node* lk = (node*)malloc(1*sizeof(node));

    lk->n = value;
    lk->next = NULL;
    if (head == NULL){
        lk->n = value;
        head = lk;
        printf("%s", "In null");
    }
    else{
        lk->n = value;
        lk->next = head;
        head = lk;
        //head->next = NULL;
        
    }

}
void display(){
    struct node* temp;
    while(temp != NULL){
        printf("%d\n", temp->n);
        temp = temp->next;
    }

}

struct node* head;

int main(){

    //this points to where u are currently
    
   head = NULL;
   insert(30);
   insert(40);
   display();

    return 0;

}
