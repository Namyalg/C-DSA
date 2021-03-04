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

//to create a node
Node* getnode(int coeff, int exp){
    Node* newNode = (Node*)malloc(1*sizeof(Node));
    newNode -> coeff = coeff;
    newNode -> exp = exp;
    newNode -> next = NULL;
    return(newNode);
}

//to create a polynomial 
//the contents will be entered from highest power to lowest power as that is how the representation is done in standard form
    
Node* create(){
    Node* head = NULL;
    int n;
    printf("****************************************\n");
    printf("Enter the powers from highest to lowest\n");
    printf("Enter number of terms : ");
    scanf("%d" , &n);
    while(n--){
        int coeff, exp;
        printf("Enter the coefficient : ");
        scanf("%d" , &coeff);
        printf("Enter the exponent : ");
        scanf("%d" , &exp);
        Node* term = getnode(coeff, exp);
        if(head == NULL){
            head = term;
        }
        else{
            //insert in the beginning
            term -> next = head;
            head = term;
        }
    }
    return head;
}


//this is a simple display function that also takes care of the sign

void display(Node* poly){
    struct Node* tr = poly;
    if(tr == NULL){
        printf("Empty polynomial !\n");
    }
    while(tr -> next != NULL){
        if(tr -> coeff < 0){
          printf(" %dx%d " ,  tr -> coeff, tr -> exp);
        }
        else if(tr -> exp == 0){
            if(tr -> coeff < 0){
                printf(" %d", tr->coeff);
            }
            else{
                printf(" +%d", tr->coeff);   
            }

        }
        else
        {
              printf(" +%dx%d " ,  tr -> coeff, tr -> exp);
        }
        
        tr = tr -> next;
    }
    if(tr -> coeff < 0)
    printf(" %dx%d " , tr -> coeff , tr -> exp);
     else if(tr -> exp == 0){
            if(tr -> coeff < 0){
                printf(" %d", tr->coeff);
            }
            else{
                printf(" +%d", tr->coeff);   
            }

        }
    else{
          printf(" +%dx%d " ,  tr -> coeff, tr -> exp);
    }
}
//--------------------------------------------------------------------------------

int not_valid(Node* poly1, Node* poly2){
    if(poly2 == NULL || poly1 == NULL){
        return 1;
    }
    return 0;
}

//in this multiply function, the duplicate exponents are also reduced
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
            //do an iteration through both the linked lists
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
                    //if power exists then add the coeff directly, else insert the node
                    int present = 0;
                    //search if coefficent exists
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

//as the head node is being used in all the computations, this is to make the display presentable in the standard form

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
    printf("*********************\n");
    printf("Enter polynomial 1\n");
    poly1 = reverse_result(create());
    printf("*********************\n");
    printf("Enter polynomial 2\n");
    poly2 = reverse_result(create());
    printf("**********************************************************************************\n");
    printf("Polynomial 1 is : ");
    display(poly1);
    printf("\n");
    printf("**********************************************************************************\n");
    printf("Polynomial 2 is  : ");
    display(poly2);
    printf("\n**********************************************************************************\n");
    result = multiply(poly1, poly2);
    if (result == NULL){
        printf("Cannot perform multiplication!");
    }
    else{
        Node* rev_res = reverse_result(result);
        printf("Result is : ");
        display(rev_res);
        printf("\n**********************************************************************************\n");
    }
    return 0;
}
