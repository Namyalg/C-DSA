#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* getnode(int val){
    Node* temp = (Node*)(malloc(sizeof(Node)));
    temp -> val = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

//easy iterative insertion into a bst and its associated traversals
Node* insert(int val, Node* root){
    Node* nd = getnode(val);
    Node* temp = root;
    if(root == NULL){
        root = nd;
    }
    else{
        while(1){
            if(val > temp -> val){
                if(temp -> right == NULL){
                    temp -> right = nd;
                    break;
                }
                else{
                    temp = temp -> right;
                }
            }
            else{
                if(temp -> left == NULL){
                    temp -> left = nd;
                    break;
                }
                else{
                    temp = temp -> left;
                }
            }
        }
    }   
    return root;
}
//height
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = height(root -> left);
    int r = height(root -> right) ;
    if (l > r){
        return l + 1;
    }
    return r + 1;
}

//count the nodes recursively

int cnt(Node* root){
    if (root == NULL){
        return 0;
    }
    return cnt(root -> left) + cnt(root -> right) + 1;
}


void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    printf("%d \n", root -> val);
    inorder(root -> right);
}

int main(){
    Node* root = NULL;
    for(int i = 0; i < 5; i++){
        int x;
        printf("Enter x : ");
        scanf("%d", &x);
        root = insert(x, root);
        inorder(root);
    }
    printf("Height is %d", height(root));
    printf("Number of nodes are %d ", cnt(root));  
    return 0;    
}
