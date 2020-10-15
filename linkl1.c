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


//Adding at beginning
//whether head is NULL
//else add behind it

//Delete 3 scenarios
//head == NULL : is empty
//more than 1 element in list delete by updating and release memory
//only one node take special care : head->next = NULL , means only one node






void insert(int val){

    node* lk = (node*)malloc(1*sizeof(node));
    lk->n = value;
    if (head == NULL){
        lk->next = NULL;
        head = lk;
    }
    else{
        lk->next = head;
        head = lk;
        
    }


}

int main(){

    struct node* head = NULL;
    //this points to where u are currently
    

   node* lk = (node*)malloc(1*sizeof(node));
    //malloc returns a pointer, u need it to be a pointer
    
    /*error*/
    
    //node* lk = (node)malloc(1*sizeof(node));
    //This will be an array but not going to return the pointer
    //similarly if sizeof(node*) will only allocate size of pointer but not the size of structure itself

    //dont hard code as u dont know the size
    
    printf("%d", sizeof(node));
    lk->n = 30;
    lk->next = NULL;
    printf("%d", lk->n);
    return 0;

}
