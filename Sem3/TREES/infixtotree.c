#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char val;
    Node* right;
    Node* left;
};
struct stack{
    int head;
    char values[1000];
};
void push(stack** obj, char val){
    //strcpy(obj.values[obj.head], val);
    (*obj)->values[(*obj)->head] = val;
    (*obj)->head += 1;
}
Node* getNode(char val){
    Node* newn = (Node*)malloc(sizeof(Node));
    //strcpy(newn->val, val);
    newn-> val = val;
    newn -> right = NULL;
    newn -> left = NULL;
    return newn;
}

int main(){
    stack* operands = (stack*)malloc(sizeof(stack));
    stack* operators = (stack*)malloc(sizeof(stack));
    operands->head = 0;
    operators->head = 0;
    printf("%d ", operands -> head);
    push(&operands, 'a');
    push(&operands, 'b');
    printf("%c ", operands->values[0]);
    return 0;
}
