
#include <stdio.h>
#include <stdlib.h>
#define MAX 100


struct node{
    struct node *left;
    char key;
    struct node *right;
};
struct node *root;

struct node *getnode(char ele){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->key = ele;
    p->left = NULL;
    p->right = NULL;
    return p;
}


struct stack{
    int top;
    struct node *nodeptrs[MAX];
};

void push(struct stack *s, struct node *p){
    s->nodeptrs[++s->top] = p;
}

struct node *pop(struct stack *s){
return s->nodeptrs[s->top--];
}


void preOrder(struct node *root){
    if(root != NULL){
        printf("%c ",root->key);
        preOrder(root -> left);
        preOrder(root-> right);
    }
}
void postOrder(struct node *root){
    if(root != NULL){
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%c ",root -> key);
    }
}
void inOrder(struct node *root){
    if(root != NULL){
    inOrder(root -> left);
    printf("%c ",root -> key);
    inOrder(root -> right);
    }
}


int pred(char op1){
    if((op1 == '+') || (op1 == '-'))
        return 1;
    if((op1 == '*')||(op1 == '/'))
        return 2;
    if(op1 == '$')
        return 3;
}


void createTree(){
    struct stack treestack;
    struct stack opstack;
    char infixexp[MAX];
    char symb;
    treestack.top = opstack.top=-1;
    printf("Enter the infix exp: \n");
    scanf("%s", infixexp);
    struct node *p,*q;
    for(int i = 0; infixexp[i] != '\0'; i++){
        symb = infixexp[i];
        if((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z')){
        p = getnode(symb);
        push(&treestack, p);
        } 
        else{
            while(opstack.top != -1 && (pred(opstack.nodeptrs[opstack.top]->key) >= pred(symb)) && pred(symb) != 3){
                q = pop(&opstack);
                if(treestack.top<1){
                    printf("ENTER VALID INFIX EXPRESSION");
                    exit(0);
                }
                q->right=pop(&treestack);
                q->left=pop(&treestack);
                push(&treestack,q);
            }
        q = getnode(symb);
        push(&opstack,q);
        }
    }
    while(opstack.top!=-1){
        q = pop(&opstack);
        if(treestack.top<1){
          printf("ENTER VALID INFIX EXPRESSION");
          exit(0);
        }
        q -> right = pop(&treestack);
        q -> left = pop(&treestack);
        push(&treestack,q);
     } 
    root = pop(&treestack);
    if(treestack.top!=-1){
    printf("Too many operands");
    exit(0);
    }
}


int main()
{
    root = NULL;
    createTree();
    printf("\nINORDER: ");
    inOrder(root);
    printf("\nPREORDER: ");
    preOrder(root);
    printf("\nPOSTORDER: ");
    postOrder(root);
    return 0;
}
