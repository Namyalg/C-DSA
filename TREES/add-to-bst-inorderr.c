
//IN INORDER TRAVERSAL, U GET THE ARRAY IN ASCENDING ORDER - >

/**
 * Definition for a binary tree node.*/
#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

struct TreeNode* getnode(int val){
    struct TreeNode* newn = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newn -> val = val;
    newn -> left = NULL;
    newn -> right = NULL;
    return(newn);
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* newn = getnode(val);
    count += 1;
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
void preOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> val);
    preOrder(root -> left);
    preOrder(root -> right);
     
}
void postOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ", root -> val);
}
int search(struct TreeNode* root, int val){
    if(root == NULL){
        return -1;
    }
    if(root -> val == val){
        return 1;
    }
    else if(root -> val > val){
        search(root -> left, val);
    }
    else{
        search(root -> right, val);
    }
    return -1;
}
int countNode(TreeNode* root){
   
    if(root == NULL){
        return 0;
    }
    countNode(root -> left);
    count += 1;
    countNode(root -> right);
    return count;
}
struct TreeNode* minValueNode(struct TreeNode* node)
{
    struct TreeNode* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct TreeNode* deleteNode(TreeNode* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            delete(root);
            return temp;
        }
        struct TreeNode* temp = minValueNode(root->right);
 
        root->val = temp->val;
 
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
int main(){
    TreeNode* root = NULL;
    int choice;
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Add a node\n2.Inorder traversal \n3.PostOrder traversal\n4.PreOrder traversal\n5.Search for a value\n6.Delete a node\n7.Count total nodes");
    while(1){
        printf("\n****************************************\nEnter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
               int val;
               printf("Enter the value : ");
               scanf("%d", &val);
               root = insertIntoBST(root, val);
               break;
            }
            case 2:{
                printf("InOrder traversal is \n");
                inOrder(root);
                break;
            }
            case 3:{
                printf("PostOrder traversal is \n");
                postOrder(root);
                break;
            }
            case 4:{
                printf("PreOrder traversal is \n");
                preOrder(root);
                break;
            }
            case 5:{
                int val;
                int present;
                printf("Enter the value to be searched for \n");
                scanf("%d", &val);
                present = search(root, val);
                if(present){
                    printf("Value is found in the BST \n");
                }
                else{
                    printf("Value is not found in the BST \n");
                }
                break;               
            }
            case 6:{
                int val;
                printf("Enter the value to be deleted for \n");
                scanf("%d", &val);
                deleteNode(root, val);
                break;               
            }
            case 7:{
                printf("Number of Nodes are %d : ");
                countNode(root);
                break;
            }
            default:
            printf("Wrong Option! \n");
        }
    }
    return(0);
}