#include<stdio.h>
#include<stdlib.h>

struct Node{
    Node* left;
    int d;
    Node* right;
};
Node* root =  NULL;
Node* getnode(int val){
    Node* newn = (Node*)malloc(sizeof(Node));
    newn -> left = NULL;
    newn -> d = val;
    newn -> right = NULL;
    return newn;
}
Node* add_to_bst(Node* root, int val){
    Node* newn = getnode(val);
    Node* temp = root;
    if(root == NULL){
        root = newn;
        return(root);
    }
    while(true){
        if(temp -> d >= val){
            if(temp -> right != NULL)
                temp = temp -> right;
            else{
                temp -> right = newn;
                break;
            }
        }
        else{
            if(temp -> left != NULL){
                temp = temp -> left;
            }
            else{
                temp -> left = newn;
                break;
            }
        }
    printf("inserted\n");
    }
    return root;
}

void postOrder(Node *root) {
        if(root == NULL){
            return;
        }
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d " , root -> d);
}
int main(){
    Node* get = NULL;
    add_to_bst(root, 23);
    add_to_bst(root, 2);
    add_to_bst(root, 12);
    add_to_bst(root, 28);
    add_to_bst(root, 221);
    //postOrder(root);
    return 0;
}