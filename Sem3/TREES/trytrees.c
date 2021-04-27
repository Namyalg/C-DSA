#include<stdio.h>
#include<stdlib.h>
//TREEEEEEEEEEEEEEEEEEE IS AN ACYCLIC thingy
//no cycles in a tree
//acyclic connected graph
//no cycles
//non-linear data structure that is acyclic and connected
//Strict binary : if all nodes have a left child and right child
//if there are n leaf nodes then 2**n - 1, cause all nodes have 2 children apart from leaves

//Complete binary : all nodes of a given level are complete
//all intermediate nodes must have 2 children each and each 
//full : 

struct Node{
    int d;
    Node* rc;
    Node* lc;
};

Node* getnode(int d){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> d = d;
    newn -> rc = NULL;
    newn -> lc = NULL;
    return newn;
}
Node* insert(Node* root, int d){
    Node* newn = getnode(d);
    if(root == NULL){
        root = newn;
        //return root;
    }
    else{
        if(root -> d > d){
            root -> lc = insert(root -> lc, d);
        }
        else{
            root -> rc = insert(root -> rc, d);
        }
    }
     return root;
}
int del(Node* root, int val){
    int present = 0;
        if(root == NULL){
            return 0;
        }
        if(root -> lc -> d == val || root -> rc -> d == val){
            printf("%d ", root -> d);
            present = 1;
        }
        else if(root -> d  > val){
            present = del(root -> lc, val);
        }
        else{
            present = del(root -> rc, val);
        }
    return present;
}
int i = 0;
int arr[100];
void get_ancestors(Node* root, int val){
    int present = 0;
        if(root == NULL){
            return;
        }
        if(root -> d == val){
            present = 1;
            return;
        }
        else{
            if(root -> d > val){
                get_ancestors(root -> lc, val);
            }
            else{
                get_ancestors(root -> rc, val);
            }
            arr[i] = root -> d;
            i += 1;
        }
       
}
int search(Node* root, int val){
    int present = 0;
        if(root == NULL){
            return 0;
        }
        if(root -> d == val){
            present = 1;
        }
        else if(root -> d > val){
            present = search(root -> lc, val);
        }
        else{
            present = search(root -> rc, val);
        }
    return present;
}
//inorder, postorder and preorder are all methods of dfs or depth first search 
//do opposite for the part where u have to get the
void get_leaves(Node* root){
    if(root == NULL){
        return;
    }
    if(root -> lc == NULL && root -> rc == NULL){
        printf("%d ", root -> d);
    }
  
    get_leaves(root -> lc);
    get_leaves(root -> rc);
}

void skip2(Node* root){
    if(root == NULL){
        return;
    }
    if(root -> lc -> lc == NULL && root -> rc -> rc == NULL){
        printf("%d ", root -> d);
    }
  
    skip2(root -> lc -> lc);
    skip2(root -> rc -> rc);
}
int count = 0;
void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root -> lc);
    count += 1;
    printf("%d ", root -> d);
    printf("%p ", root -> lc);
    printf("%p \n", root -> rc);
    inorder(root -> rc);
}
//all operations with respect to trees have been done here
//insert
//seargc
//get leaf nodes
//get non leaf nodes
//get totalnumbe rof nodes
int front = 0;
int rear = 0;
int q[20];
int dq(){
    int st = front;
    front += 1;
    return q[st];
}
void eq(int val){
    q[rear] = val;
    rear += 1;
}
void bfs(Node* root){
    eq(root -> d);
    while(front != rear){
        int f = dq();
        printf("%d " , f);
        root = root -> lc;
        eq(root -> lc -> d);
        eq(root -> rc -> d);
    }
}
int main(){
    //k array tree, means number of children a node can have
    //2 array tree, 3 array tree, n array tree or arrayness
    Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 25);
    root = insert(root, 16);
    root = insert(root, 89);
    root = insert(root, 12);
    root = insert(root, 500);
    inorder(root);
    printf("Number of nodes are %d\n", count);
    int find;
    printf("\nEnter element to be delted  \n");
    scanf("%d", &find);
    //int present = del(root, find);
    //printf("\n%d\n" , present);
    inorder(root);
    //printf("\nThe leaf nodoes are : \n");
    //get_leaves(root);
    get_ancestors(root, find);
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    //bfs(root);
}