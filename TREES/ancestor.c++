#include <iostream>
#include <cstdlib>
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
class BinarySearchTree
{
private:


    struct TreeNode
    {
        int key; 
        TreeNode* left;
        TreeNode* right; 
    };
    TreeNode* root; //root pointer

public:
    void insert(int value)
    {
         TreeNode* leaf_node; 
         TreeNode*curr_node; 
         TreeNode* t = new TreeNode;
         t->key = value; 
         t->right = NULL;
         t->left = NULL;

         if(root == NULL)
         {
             root  = t; //t is root now
         }
         else
         {

             curr_node = root;

             while(curr_node != NULL)
             {

                    leaf_node = curr_node;
                    if(value > curr_node ->key)
                    {
                        curr_node = curr_node->right;
                    }
                    else
                    {
                        curr_node = curr_node->left;
                    }
             }
            if(value > leaf_node ->key)
            {
                leaf_node->right = t;
            }
            else
            {
                leaf_node->left = t;
            }

         }
    }
    void inorder(){
        inorder(root);
    }
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root -> left);
        cout<<root -> key<<" ";
        inorder(root -> right);
    }
    void search(TreeNode* root, int val){
        if(root == NULL){
            return;
        }if(root -> key == val){
            //cout<<"Found ";
            return;
        }
        else{ 
             if(root -> key > val){
                //s.push(root -> key);
                search(root -> left, val);
            }
            else{
                //s.push(root -> key);
                search(root -> right, val);
            }
            cout<<root -> key <<" ";           
            }
        }

    void search(int val){
        search(root, val);
    }
};
int main(int argc, char * argv[])
{
    //Testing The Code
    BinarySearchTree t;
    t.insert(8);
    t.insert(3);
    t.insert(1);
    t.insert(5);
    t.insert(10);
    t.insert(9);
    t.insert(12);
    t.insert(11);
    t.search(11);
    return 0;
}