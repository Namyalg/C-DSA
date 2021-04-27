#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    Node* next;
};

struct Node* getnode(int val){
    Node* newn = (Node*)malloc(sizeof(Node));
    newn -> val = val;
    newn -> next = NULL;
    return newn;
}

void insert(Node** head, Node** tail, int val){
    Node* newn = getnode(val);
    if((*head) == NULL){
        (*head) = newn;
        (*tail) = newn;
    }
    else{
        newn -> next = (*head);
        (*head) = newn;
    }
}
void createll(int num, Node** head, Node** tail){
    int d = 0;
    while(num > 0){
        d = num % 10;
        Node* newn = getnode(d);
        if((*head) == NULL){
            (*head) = newn;
            (*tail) = newn;
        }
        else{
            (*tail) -> next = newn;
            (*tail) = newn;
        }
        num = num / 10;
    }
}
void display(Node* head){
    while(head!= NULL){
        printf("%d", head -> val);
        head = head -> next;
    }
}
void add(Node* head1, Node* head2){
    int carry = 0;
    Node* result = NULL;
    Node* restail = NULL;
    Node* temp = head1;
    while(head1 != NULL && head2 != NULL){
        head1 -> val += carry + head2 -> val;
        carry = (head1 -> val) / 10;
        (head1 -> val) = (head1 -> val) % 10;
        insert(&result, &restail, (head1 -> val));
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    while(head1 != NULL){
        head1 -> val += carry;
        carry = (head1 -> val) / 10;
        head1 -> val = (head1 -> val) % 10;
        insert(&result, &restail, (head1 -> val));
        head1 = head1 -> next;
    }
    while(head2 != NULL){
        head2 -> val += carry;
        carry = (head2 -> val) / 10;
        head2 -> val = (head2 -> val) % 10;
        insert(&result, &restail, (head2 -> val));
        head2 = head2 -> next;
    }
    if(carry != 0){
        insert(&result, &restail, carry);
    }
    printf("The sum is : ");
    display(result);
    printf("\n");
    
}
int main(){
    int num1, num2;
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    printf("Enter number 1 : ");
    scanf("%d" , &num1);
    printf("Enter number 2 : ");
    scanf("%d" , &num2);
    if(num1 <= 0 || num2 < 0){
        printf("Only long positive integers can be added !");
    }
    else{
        createll(num1, &head1, &tail1);
        createll(num2, &head2, &tail2);
        add(head1, head2);
    }
    return 0;
}