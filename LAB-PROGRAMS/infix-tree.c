#include<stdio.h>
#include<stdlib.h>

struct Node{
    char val;
    Node* left;
    Node* right;
};
Node* getnode(char val){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> val = val;
    newn -> left = NULL;
    newn -> right = NULL;
    return newn;
}
void display(Node* root){
    printf("%c ", root -> val);
}
int main(){
    Node* root = NULL;
    char val;
    printf("Enetr a valu : ");
    scanf("%c", &val);
    root = getnode(val);
    display(root);
    return 0;
}