#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    Node* next;
};

//circular linked list
struct Node* getnode(int val){
    Node* newn = (Node*)malloc(sizeof(Node));
    newn -> val = val;
    newn -> next = newn;
    return newn;
}
//add to the end
void insert(Node** head, int val){
    Node* newn = getnode(val);
    if((*head) == NULL){
        (*head) = newn;
    }
    else{
        newn -> next = (*head) -> next;
        (*head) -> next = newn;
    }
}

void dis(Node* head){
    Node* ne = head -> next;
    while(ne != head){
        printf("%d ", ne -> val);
        ne = ne -> next;
    }
    printf("%d \n", ne -> val);
}

//pass it by reference
/*void insrt(Node** head, int val){
     Node* newn = getnode(val);
        if((*head) == NULL){
            (*head) = newn;
        }
        else{
            newn -> next = (*head) -> next;
            (*head) -> next = newn;
            (*head) = newn;
        }
}*/
void createll(int num, Node** head){
    int d = 0;
    while(num > 0){
        d = num % 10;
        Node* newn = getnode(d);
        if((*head) == NULL){
            (*head) = newn;
        }
        else{
            newn -> next = (*head) -> next;
            (*head) -> next = newn;
            (*head) = newn;
        }
        num = num / 10;
    }
    Node* newn = getnode(0);
        if((*head) == NULL){
            (*head) = newn;
        }
        else{
            newn -> next = (*head) -> next;
            (*head) -> next = newn;
            (*head) = newn;
        }
}

void add(Node* head1, Node* head2){
    int carry = 0;
    Node* h1 = head1;
    Node* h2 = head2;
    //as head points to the end, it is added from the end
    head1 = head1 -> next;
    head2 = head2 -> next;
    Node* result = NULL;
    while(head1 != h1 && head2 != h2){
        head1 -> val += carry + head2 -> val;
        carry = (head1 -> val) / 10;
        (head1 -> val) = (head1 -> val) % 10;
        insert(&result, (head1 -> val));
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    while(head1 != h1){
        head1 -> val += carry;
        carry = (head1 -> val) / 10;
        head1 -> val = (head1 -> val) % 10;
        insert(&result, (head1 -> val));
        head1 = head1 -> next;
    }
    while(head2 != h2){
        head2 -> val += carry;
        carry = (head2 -> val) / 10;
        head2 -> val = (head2 -> val) % 10;
        insert(&result, (head2 -> val));        
        head2 = head2 -> next;
    }
    if(carry != 0){
        insert(&result, carry);
    }
    printf("The sum is : ");
    Node* t = result -> next;
    while(t !=  result){
        printf("%d", t -> val);
        t = t -> next;
    }   
    printf("%d", t -> val);
    printf("\n");
    
}
int main(){
    int num1, num2;
    Node* head1 = NULL;
    Node* head2 = NULL;
    printf("Enter number 1 : ");
    scanf("%d" , &num1);
    printf("Enter number 2 : ");
    scanf("%d" , &num2);
    if (num1 == 0){
        printf("The sum is %d ", num2);
    }
    else if(num2 == 0){
        printf("The sum is %d ", num1);
    }
    else{
        if(num1 < 0 || num2 < 0){
            printf("Only long positive integers can be added !");
        }
        else{
            //passed by reference here
            createll(num1, &head1);
            printf("Number 1 as a linked list \n");
            dis(head1);
            createll(num2, &head2);
            printf("Number 2 as a linked list \n");
            dis(head2);
            add(head1, head2);
        }
    }
    return 0;
}