//multiplication of polynomials

#include<stdio.h>
#include<stdlib.h>

//in each node, this is the representation of the polynomial
//****************************
 //coff    * exp    * next *
//****************************
struct Node{
    int coeff;
    int exp;
    Node* next;
}*head;
int y;
//to create a node
Node* getnode(int coeff, int exp){
    Node* newNode = (Node*)malloc(1*sizeof(Node));
    newNode -> coeff = coeff;
    newNode -> exp = exp;
    newNode -> next = NULL;
    return(newNode);
}

Node* create(){
    Node* head = NULL;
    int n;
    printf("Enter the powers from lowest to highest\n");
    printf("Enter number of terms : ");
    scanf("%d" , &n);
    while(n--){
        int coeff, exp;
        printf("Enter the coeff : ");
        scanf("%d" , &coeff);
        printf("Enter the exponent : ");
        scanf("%d" , &exp);
        Node* term = getnode(coeff, exp);
        if(head == NULL){
            head = term;
        }
        else{
            term -> next = head;
            head = term;
        }
    }
    return head;
}

void display(Node* poly){
    struct Node* tr = poly;
    if(tr == NULL){
        printf("Empty polynomial !\n");
    }
    while(tr -> next != NULL){
        printf("%dx%d + " ,  tr -> coeff, tr -> exp);
        //printf("x");
        //printf("%d" , tr->exp);
        //printf("+");
        tr = tr -> next;
    }
    printf("%dx%d" , tr -> coeff , tr -> exp);
}
Node* multiply(Node* poly1, Node* poly2){
    Node* pdt = NULL;
    if(poly2 == NULL){
        return poly1;
    }
    if(poly1 == NULL){
        return poly2;
    }    
}
int main(){

    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL
    poly1 = create();
    poly2 = create();
    display(poly1);    
    display(poly2);
    result = multiply(poly1, poly2);
    printf("Result is \n");
    display(result);
    return 0;
}


