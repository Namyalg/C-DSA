#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;
int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        int a[l1+1][l2+1];
        int m = -4;
        for(int i = 0; i <= l1; i++){
            for(int j = 0; j <= l2; j++){
                if(i == 0 || j == 0){
                    a[i][j] = 0;
                }
                else{
                    if(text1[i] == text2[j]){
                        a[i][j] = a[i-1][j-1] + 1;
                            m = max(a[i][j], m);
                    }
                    else{
                        a[i][j] = 0;
                    }
                }
            }
        }
        return m;
    }
int main(){
    string a = "cool";
    string b = "tooolbox";
    cout<<longestCommonSubsequence(a,b);
}