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
    while(head!= NULL){
        printf("Row %d \n", head -> r);
        printf("Column %d \n", head -> c);
        printf("Value %d \n", head -> val);
        head = head -> next;
    }
}
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
    printf("\nEnter a row between 0 and %d \n" , rows - 1);
    printf("Enter a column between 0 and %d \n\n", columns - 1);
    while(non_zero--){
        int r, c, val;
        printf("Enter the row, column and value : ");
        scanf("%d%d%d", &r, &c, &val);
        if(r >= rows || c >= columns){
            printf("INVALID INDEX \n");
            printf("************************************\n");
            printf("Enter a row between 0 and %d", rows - 1);
            printf("\nEnter a column between 0 and %d \n", columns - 1);
            printf("************************************\n\n");
            non_zero = non_zero + 1;
        }
        else{
            insert(&head, r, c, val);
        }
    }
    printf("*********************************************\n");
    printf("\n This is the sparse matrix \n");
    struct Node* move = head;
    printf("\n");
    int present = 0;
    for(int i = 0 ; i < rows; i++){
        
        for(int j = 0; j < columns; j++){
            present = 0;
            while(move != NULL){
                if(move -> r == i && move -> c == j){
                    present = 1;
                    printf("%d ", move -> val);
                    //printf("%d %d %d\n", i ,j , move -> val);
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