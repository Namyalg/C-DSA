#include<stdio.h>
#include<stdlib.h>

struct Node{
    char val;
    Node* left;
    Node* right;
};
Node* root = NULL;
Node* getNode(char val){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> val = val;
    newn -> left = NULL;
    newn -> right = NULL;
    return newn;
}
void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    printf("%d ", root -> val);
    inOrder(root -> right);
}
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> val);
    preOrder(root -> left);
    preOrder(root -> right);
}
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ", root -> val);
}
void add(Node* root, int val){
    Node* newn = getNode(val);
    if(root == NULL){
        root = newn;
    }
    else{
        if(val > root -> val){
            if(root -> right == NULL){
                root -> right = newn;
            }
            else{
                add(root -> right, val);
            }
        }
        else{
            if(root -> left == NULL){
                root -> left = newn;
            }
            else{
                add(root -> left, val);
            }
        }
    }
}
int countTheNodes(Node* root){
    int count = 0;
    if(root == NULL){
        return 0;
    }
    return(countTheNodes(root -> left) + countTheNodes(root -> right));
}
int main(){
    int choice;
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Add\n2.Inorder\n3.PostOrder\n4.PreOrder\n");
    while(1){
        printf("\n");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
               int val;
               printf("Enter the value \n");
               scanf("%d", &val);
               add(root, val);
               break;
            }
            case 2:{
                inOrder(root);
                break;
            }
            case 3:{
                postOrder(root);
                break;
            }
            case 4:{
                preOrder(root);
                break;
            }
            default:
            printf("Wrong Option! \n");
        }
    }
    return(0);
}