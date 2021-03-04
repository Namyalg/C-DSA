#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    int r,c;
    Node* next;
    Node* prev;
};

struct Node* getnode(int r, int c, int val){
    Node* newn = (Node*)malloc(sizeof(Node));
    newn -> r = r;
    newn -> c = c;
    newn -> val = val;
    newn -> next = NULL;
    newn -> prev = NULL;
    return newn;
}

//insert at head of doubly linked list
void insert(Node** head, int r, int c, int val){
    Node* newn = getnode(r, c, val);
    if((*head) == NULL){
        (*head) = newn;
    }
    else{
        newn -> next = (*head);
        (*head) -> prev = newn;
        (*head) = newn;
    }
}

void display(Node* head){
    printf("\n");
    printf("Row     Column      Value\n");
    while(head!= NULL){
        printf("%d ", head -> r + 1);
        printf("        %d ", head -> c + 1);
        printf("        %d \n", head -> val);
        head = head -> next;
    }
}
//based on 1 indexing it is used here
int main(){
    int rows, columns;
    Node* head = NULL;
    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns : ");
    scanf("%d", &columns);
    int non_zero;
    printf("Enter the number of non-zero values : ");
    scanf("%d", &non_zero);
    if(non_zero > rows*columns){
        printf("The matrix cannot have more than %d values ", rows*columns);
    }
    else{
    printf("************************************\n");
    printf("INSTRUCTIONS \n");
    printf("************************************\n");
    printf("\nEnter a row between 1 and %d \n" , rows);
    printf("Enter a column between 1 and %d \n\n", columns );
    while(non_zero--){
        int r, c, val;
        printf("Enter the row, column and value : ");
        scanf("%d%d%d", &r, &c, &val);
        if(r > rows || c > columns || c < 1 || r < 1){
            printf("INVALID INDEX \n");
            printf("************************************\n");
            printf("Enter a row between 1 and %d", rows );
            printf("\nEnter a column between 1 and %d \n", columns);
            printf("************************************\n\n");
            non_zero = non_zero + 1;
        }
        else{
            insert(&head, r-1, c-1, val);
        }
    }
    printf("\n************************************************\n");
    printf("The contents of the doubly-linked list are : \n");
    display(head);
    struct Node* move = head;
    
    printf("*********************************************\n");
    printf("\n This is the sparse matrix \n");

    printf("\n");
    int check[rows][columns];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            check[i][j] = 0;
        }
    }
    int present = 0;
    for(int i = 0 ; i < rows; i++){
        for(int j = 0; j < columns; j++){
            present = 0;
            while(move != NULL){
                if(move -> r == i && move -> c == j && check[i][j] == 0){
                    present = 1;
                    check[i][j] = 1;
                    printf("%d ", move -> val);
                }
                move = move -> next;
            }
            move = head;
            if(present != 1){
                printf("%d ", 0);
            }
        }
        printf("\n");
        }
    }
    return 0;
}