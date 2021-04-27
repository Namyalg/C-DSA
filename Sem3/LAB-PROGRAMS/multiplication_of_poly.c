//multiplication of polynomials
//This works perfectly for all situations
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
    printf("Enter the powers from highest to lowest\n");
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
        tr = tr -> next;
    }
    printf("%dx%d" , tr -> coeff , tr -> exp);
}
//--------------------------------------------------------------------------------

int not_valid(Node* poly1, Node* poly2){
    if(poly2 == NULL || poly1 == NULL){
        return 1;
    }
    return 0;
}

Node* multiply(Node* poly1, Node* poly2){
    Node* result = NULL;
    if(not_valid(poly1, poly2)){
        return result;
    } 
    else{
        Node* h1 = poly1;
        Node*h2 = poly2;
        Node* temp = h2;
        while(poly1 != NULL){
            temp = h2;
            while(temp != NULL){
                int coeff = (poly1 -> coeff) * (temp -> coeff);
                int exp = (poly1->exp) + (temp->exp); 
                Node* newn = getnode(coeff, exp);
                if(result == NULL){
                    result = newn;
                }
                else{
                    Node* move = result;
                    int present = 0;
                    while(move != NULL){
                        if((move -> exp) == exp){
                            move -> coeff += coeff;
                            present = 1;
                        }
                        move = move -> next;
                    }
                    if(present != 1){
                        newn -> next = result;
                        result = newn;
                    }
                }
                temp = temp -> next;
            }
            poly1 = poly1 -> next;
        }
        return result;
    }
}

Node* reverse_result(Node* res){
    if(res == NULL){
        return res;
    }
    Node* prev = NULL;
    Node* nxt = NULL;
    Node* curr = res;
    while(curr != NULL){
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    res = prev;
    return res;
}

int main(){

    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    printf("Enter polynomial 1\n");
    poly1 = reverse_result(create());
    printf("Enter polynomial 2\n");
    poly2 = reverse_result(create());
    printf("Polynomial 1 is : ");
    display(poly1);
    printf("\n");    
    printf("Polynomial 2 is  : ");
    display(poly2);
    printf("\n");
    result = multiply(poly1, poly2);
    Node* rev_res = reverse_result(result);
    printf("Result is : ");
    display(rev_res);
    printf("\n");
    return 0;
}


