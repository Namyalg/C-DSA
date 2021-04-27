#include<iostream>
#include<bits/stdc++.h>
#define MAX 10000

using namespace std;

int stack[MAX];
int top = 0;

void push(int el){
    if(top >= MAX){
        cout<<"Overflow" <<endl;
    }
    else{
        stack[top++] = el;
    }
}

int pop(){
    if (top == 0){
        return(-1);
    }
    else{
        //top = top - 1;
        return(stack[top--]);
    }
}
void display(){
    for(int i = 0; i < top; i++){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int evaluate(int exp[], int size){
    int res;
    for(int i = 0; i < size; i++){
        if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/"){
            int op2 = pop();
            int op1 = pop();
            if (exp[i] == "+"){
                res = op1 + op2;
            }
            if (exp[i] == "-"){
                res = op1 - op2;
            }
                
            if (exp[i] == "*"){
                res = op1 * op2;
            }
            if (exp[i] == "/"){
                res = op1 / op2;
            }
            push(res);
        
        }
        else{
            push(stoi(exp[i]));
        }
    }
    return(pop());
}
int main(){
    string exp = "43*5+";
    int size = exp.size();
    int arr[size];
    for(int i = 0;i < 5; i++){
        arr[i] = exp[i];
    }
    cout<<evaluate(arr, size);
    return 0;
}
