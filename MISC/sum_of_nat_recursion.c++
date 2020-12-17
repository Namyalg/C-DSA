#include<iostream>

//sum of natural numbers using recursion
using namespace std;

//no additional numbers or loops, u have a base case and go ahead with that
int sum(int n){
    if (n == 0){
        return 0;
    }
    else{
        return (n + sum(n-1));
    }

}

int main(){

    cout<<sum(15)<<endl;
    return 0;
    
}
