#include<stdio.h>
#include<stdlib.h>
int count = 0;

//basic structure of tree node
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

//dynamically allocating memory to create a tree node
struct TreeNode* getnode(int val){
    struct TreeNode* newn = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newn -> val = val;
    newn -> left = NULL;
    newn -> right = NULL;
    return(newn);
}

//in the insert function, the position of insertion of the node is found based on the property of the binary search tree

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* newn = getnode(val);
    count += 1;
    struct TreeNode* store = root;

//if no root exists, the first node created is made the root   
 if(root == NULL){
        root = newn;
        return root;
    }
    else{

//the loop continues until the location is found, after which the loop breaks
        while(true){
            //if the value to be inserted is less than the root, then move leftwards
if(val <= root -> val){
                if(root -> left != NULL){
                    root = root -> left;
                }
                else{
//If the position of insertion has been found on the left, then create a new node to the left and break
                    root -> left = newn;
                    break;
                }
            }
            else{
//if the value to be inserted is greater than the root, move rightwards

                if(root -> right != NULL){
                    root = root -> right;
                }
                else{
//If the position of insertion has been found on the right, then create a new node to the left and break
                    root -> right = newn;
                    break;
                }
            }
        }
        return(store);
    }
}

//simple recursive function that goes, Left, Root and Right
void inOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    printf("%d ", root -> val);
    inOrder(root -> right);
     
}

//A simple recursive function that goes Root, Left, Right
void preOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> val);
    preOrder(root -> left);
    preOrder(root -> right);
     
}

//A simple recursive function that goes Left, Right, Root

void postOrder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ", root -> val);
}

//A search function implemented based on property of BST
TreeNode* search(struct TreeNode* root, int val){
    if(root == NULL){
            return NULL;
        }
        if(root -> val == val){
            return root;
        }
        if(root -> val >= val){
            root = search(root -> left, val);
        }
        else if(root -> val < val){
            root = search(root -> right, val);
        }
        return root;
}

//A functionality to count the number of nodes
int countNode(TreeNode* root){
   
    if(root == NULL){
        return 0;
    }
    countNode(root -> left);
    count += 1;
    countNode(root -> right);
    return count;
}

/*In the delete function there are 3 cases that can be encountered
A pointer to the leaf is maintained on searching for the node
When the node to be deleted is the leaf, the link to the leaf is deleted
When the leaf has a right child and left == NULL, then the link to the root, is connected to the right child, deleting the node with the value
When the leaf has a left child and right == NULL, then the link to the root, is connected to the left child, deleting the node with the value
In case the node to be deleted has both the left and right subtree, then the inorder successor, i.e the minimum value in the right subtree is replaced with the node and minimum value node in the right subtree is deleted

*/

TreeNode* deleteNode(TreeNode* root, int val) {
        if (!root) return root;
        
        if (val < root->val) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->val) {
            root->right = deleteNode(root->right, val);
        } else {
            /* Leaf node case */
            if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            /* 1 child case */
            if (!root->left || !root->right) {
                TreeNode *ret = root->left ? root->left : root->right;
                delete(root);
                return ret;
            }
            /* 2 child case */
            if (root->left && root->right) {
                TreeNode *tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

int main(){
    TreeNode* root = NULL;
    int choice;
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Add a node\n2.Inorder traversal \n3.PostOrder traversal\n4.PreOrder traversal\n5.Search for a value\n6.Delete a node\n");
    while(1){
        printf("\n****************************************\nEnter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
               int val;
               printf("Enter the value : ");
               scanf("%d", &val);
               root = insertIntoBST(root, val);
               inOrder(root);
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
                root = deleteNode(root, val);
                break;               
            }
            default:
            printf("Wrong Option! \n");
        }
    }
    return(0);
}

