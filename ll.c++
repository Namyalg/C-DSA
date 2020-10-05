#include <bits/stdc++.h>

using namespace std;

//stack has limited space

struct stk{
    int a;
    struct stk* next;
};

struct stk* top = NULL;

void insert(int val){
    struct stk* temp = (struct stk*)malloc(sizeof(struct stk));
    temp -> a = val;
    temp -> next = top;
    top = temp;
}

void pop(){
    while(top != NULL){
        cout << top -> next << " ";
        top = top -> next;
        
    }
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(5);  
    struct stk* head;
    while(top != NULL){
        cout << top -> a << " ";
        top = top -> next;
    }
    return 0;
}
