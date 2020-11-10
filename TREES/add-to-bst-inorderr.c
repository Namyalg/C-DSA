
//IN INORDER TRAVERSAL, U GET THE ARRAY IN ASCENDING ORDER - >

/**
 * Definition for a binary tree node.*/
#include<stdio.h>
#include<stdlib.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 TreeNode* root = NULL;

struct TreeNode* getnode(int val){
    struct TreeNode* newn = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newn -> val = val;
    newn -> left = NULL;
    newn -> right = NULL;
    return(newn);
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* newn = getnode(val);
    struct TreeNode* store = root;
    if(root == NULL){
        root = newn;
        return root;
    }
    else{
        while(true){
            if(val <= root -> val){
                if(root -> left != NULL){
                    root = root -> left;
                }
                else{
                    root -> left = newn;
                    break;
                }
            }
            else{
                if(root -> right != NULL){
                    root = root -> right;
                }
                else{
                    root -> right = newn;
                    break;
                }
            }
        }
        return(store);
    }
}
void inOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    printf("%d ", root -> val);
    inOrder(root -> right);
     
}


int main(){
    //TreeNode* root == NULL;
    root = insertIntoBST(root, 24);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 243);
    root = insertIntoBST(root, 43);
    printf("Here in the main\n");
    inOrder(root);
    return 0;
}