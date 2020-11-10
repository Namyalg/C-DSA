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
//search in BST recursively
int search(TreeNode* root, int val){
    //if the condition to catch this is not added will lead to a segmentation ault
    //it is more at a hardware level so a software solution may not be very useful therr
    if(root == NULL){
        return -1;
    }
    if(root -> val == val){
        return 1;
    }
    if(root->val > val){
        printf("%d" , root -> val);
        root = root -> left;
        return(search(root, val));
    }
    else{
         printf("%d" , root -> val);
        root = root -> right;
        return(search(root, val));
    }
    return -1;
    
}
void ancestor(TreeNode* root, int val){
    //if the condition to catch this is not added will lead to a segmentation ault
    //it is more at a hardware level so a software solution may not be very useful therr
    int arr[100];
    int i = 0;
    if(root -> val == val){
        for(int j = 0; j < i; j++){
            printf("%d ", arr[j]);
        }
    }
    if(root->val > val){
        printf("%d ", root -> val);
        arr[i] = root -> val;
        root = root -> left;
       
        i += 1;
        ancestor(root, val);
    }
    else{
        printf("%d ", root -> val);
        arr[i] = root-> val;
        root = root -> right;
        i += 1;
        ancestor(root, val);
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
void inOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    printf("%d ", root -> val);
    inOrder(root -> right);    
}
void preOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> val);
    preOrder(root -> left);
    preOrder(root -> right);   
}
//height of a binary tree
//the height of a node is the max edges it takes to reach a leaf node
//the depth is the number of edges away from the root node to a particular node
int heit(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        return(1 + (heit(root -> left) > heit(root -> right) ? heit(root->left) : heit(root -> right)) );
        //return(max(heit(root -> left, root -> right)));
    }
}

int main(){
    //TreeNode* root == NULL;
    root = insertIntoBT(root, 6);
    root = insertIntoBT(root, 4);
    root = insertIntoBT(root, 9);
    root = insertIntoBT(root, 2);
    root = insertIntoBT(root, 5);
    root = insertIntoBT(root, 8);
    root = insertIntoBT(root, 12);
    root = insertIntoBT(root, 10);
    root = insertIntoBT(root, 14);
    //printf("PostOrder traversal is as shown\n");
    //postOrder(root);
    int f;
    TreeNode* st = root;
    printf("Enter the element to be searched\n");
    scanf("%d", &f);
    int find = search(root, f);
    if(find == 1){
        printf("Element is found\n");
       /* printf("Ancestor of a given value \n");
        ancestor(st, f);*/
    }
    else{
        printf("Element not found\n");
    }
    /*printf("Height of a tree : ");
    printf("%d ", heit(root));*/
    return 0;
}