//no of non-zero elements = approx equal to the number of rows/columns ONLY
//basically the number of non zero are in minority
//network theorem, partial differential equations
//we are using a coordinate list, row, colu, val
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int r, c;
    int val;
    Node* nxt;
    Node* bhd;
}*head = NULL, *header = NULL, *start = NULL;

Node* getnode(int r, int c, int val){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> r = r;
    newn -> c = c;
    newn -> val = val;
    newn -> nxt = NULL;
    newn -> bhd = NULL;
    return newn;
}

/*void insert(int r, int c, int val){
    Node* newn = getnode(r, c, val);
    if(head == NULL){
        head = newn;
    }
    else{
        newn -> nxt = head;
        head -> bhd = newn;
        head = newn; 
    }
}*/
void insert(int r, int c, int val){
    Node* newn = getnode(r, c, val);
    if(head == NULL){
        head = newn;
        start = newn;
    }
    else{
        while(head -> nxt != NULL){
            head = head -> nxt;
        }
        head -> nxt = newn;
        newn -> bhd = head;
    }
}


void display(){
    Node* move = start;
    if(start == NULL){
        printf("Empty list\n");
    }
    while(move != NULL){
        printf("%d %d %d \n", move -> r, move -> c, move -> val);
        move = move -> nxt;
    }
}
//u head a header node
/********************************
rows * colums * number of non zero
**********************************
*/
//also need to display the matrix as well as the zeros, see what is there and then see
//its really stupid but cant help :(

int main(){
    while(true){
        int r, c, val;
        printf("Enter row \n");
        scanf("%d", &r);
        printf("Enter col \n");
        scanf("%d", &c);
        printf("Enter val \n");
        scanf("%d", &val);
        insert(r, c, val);
        display();
    }
    return 0;
}