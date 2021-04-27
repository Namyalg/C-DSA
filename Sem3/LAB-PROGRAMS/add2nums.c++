#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main(){
    string a = "23982394823842348209443455";
    string b = "20302802382882023004033453";
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    cout<<"Reverse of number 1 is " <<a<<endl;
    cout<<"Reverse of number 2 is " <<b<<endl;
    int sum = 0;
    int carry = 0;
    int i, j;
    string s= "";
    for(i = 0, j = 0; a[i] != '\0', b[i] != '\0'; i++, j++){
        sum += a[i] + b[j];
        carry = sum / 10;
        sum = sum % 10;
        s += to_string(sum);
    }
    cout<<s;
    return 0;
}