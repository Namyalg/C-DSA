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

struct TreeNode* insertIntoBT(struct TreeNode* root, int val){
    struct TreeNode* newn = getnode(val);
    if(root == NULL){
        root  = newn;
    }
    else{
        if(root -> val >= val){
            root-> left = insertIntoBT(root -> left, val);
        }
        else{
            root-> right= insertIntoBT(root -> right, val);
        }
    }
    return root;
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
void postOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ", root -> val);
   
}


int main(){
    //TreeNode* root == NULL;
    root = insertIntoBT(root, 24);
    root = insertIntoBT(root, 2);
    root = insertIntoBT(root, 4);
    root = insertIntoBT(root, 243);
    root = insertIntoBT(root, 43);
    printf("Here in the main\n");
    postOrder(root);
    return 0;
}