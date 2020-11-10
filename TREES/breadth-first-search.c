#include<stdio.h>
#include<stdlib.h>

struct Node{
    int d;
    Node* left;
    Node* right;
}*root = NULL;

Node* getnode(int d){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> d = d;
    newn -> left = NULL;
    newn -> right = NULL;
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
            root -> left = insert(root -> left, d);
        }
        else{
            root -> right = insert(root -> right, d);
        }
    }
    return root;
}
void inorder(Node* root){
    Node* temp = root;
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    printf("%d ", root -> d);
    inorder(root -> right);
}
int front = 0;
int rear = 0;
 int qu[1000];
void enqueue(int el){
    rear += 1;
    qu[rear] = el;
}
void dequeue(){
    printf("%d ", qu[front]);
    front += 1;
}
//int arr[10];
int i = 0;
int arr[10];

void bfs(Node* root){
    if(root == NULL){
        return;
    }
    arr[i] = 
}
/*void bfs(Node* root){
    int arr[100];
    Node* temp = root;
    if(root == NULL){
        printf("Tree has no nodes");    
    }
    else{
        int level = 1;
        qu[0] = root -> d;
        int not_null = 1;
        while(not_null){
            enqueue(root -> left ->d);
            enqueue(root -> right -> d);
            for(int i = 0; i < level; i++){
                dequeue();
            }
        level = level * 2;
        bfs(root -> left);
        bfs(root -> right);
        not_null = 0;
        break;
        } 
    }
}*/
int main(){
    root = insert(root, 12);
    root = insert(root, 1);
    root = insert(root, 22);
    root = insert(root, 14);
    root = insert(root, 133);
    root = insert(root, 138);
    root = insert(root, 1);
    inorder(root);
    bfs(root);
    return 0;
}








