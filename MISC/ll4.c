#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int c;
    Node* next;
};

Node* getnode(int c){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> c = c;
    newn -> next = NULL;
    return newn;
}
void create_poly(Node** head, Node**tail, int n){
    int d;
    while(n > 0){
        d = n % 10;
        Node* poly = getnode(d);
        if((*head) == NULL){
            (*head) = poly;
            (*tail) = poly;
        }
        else{
            (*tail) -> next = poly;
            (*tail) = poly;
        }
        n = n / 10;
    }
}
void display(Node* head){
    while(head != NULL){
        printf("%d ", head -> c);
        head = head -> next;
    }
}

int length(Node* head){
    int count = 0;
    while(head != NULL){
        count += 1;
        head = head -> next;
    }
    return count;
}
int add(Node* head1, Node* head2, Node* tail1, Node* tail2, int l1, int l2){
    int carry = 0;
    if(l1 > l2){
        Node* zer = head2;
        while(zer != NULL){
            zer = zer -> next;
        }
        while(head2 != NULL){
            head1 -> c += carry + head2 -> c;
            carry = (head1 -> c) / 10;
            head1 -> c = (head1 -> c) % 10;
            printf("%d ", head1 -> c);
            head2 = head2 -> next;
            head1 = head1 -> next;
        }
        while(head1 != NULL){
            head1 -> c = (carry + head1 -> c) % 10;
            //printf("\n carry is %d \n", carry);
            carry = (head1 -> c) / 10;
            printf("%d ", head1 -> c);
            head1 = head1 -> next;
        }
        printf("Carry is %d", carry);
    }
    return 0;
}
int main(){
    int num1, num2;
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int l1 = 0, l2 = 0;
    printf("Enter number1 ");
    scanf("%d", &num1);
    printf("Enter number2 ");
    scanf("%d", &num2);
    create_poly(&head1, &tail1, num1);
    create_poly(&head2, &tail2, num2);
    l1 = length(head1);
    l2 = length(head2);
    //display(head1);
    //display(head2);
    printf("\n%d ", add(head1, head2, tail1, tail2, l1, l2));   
    return 0;
}