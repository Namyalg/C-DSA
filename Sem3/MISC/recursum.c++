#include<iostream>

//sum of the digits of a number using recursion
using namespace std;

int recur(int n){
    if (n <= 0){
        return n;
    }
    else{
        return ((n % 10) + recur(n / 10));
    }

}

int main(){

    cout<<recur(12048930)<<endl;
    return 0;
    
}
