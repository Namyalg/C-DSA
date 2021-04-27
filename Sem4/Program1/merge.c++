#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right, int n, int m, vector<int> temp){
    int l = 0, r = 0;
    while(l < n && r < m){
        if(left[l] < right[r]){
            temp.push_back(left[l++]);
        }
        else{
            temp.push_back(right[r++]);
        }
    }
    while(l < n){
        temp.push_back(left[l++]);
    }
    while(r < m){
        temp.push_back(right[r++]);
    }
    return temp;
}

int main(){
    int n,  m;
    vector<int> left;
    vector<int> right;
    cout<<"Enter size of array 1 "<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        left.push_back(x);
    }

    cout<<"\nEnter size of array 2 "<<endl;
    cin>>m;
    for(int i = 0; i < m; i++){
        int x;
        cin>>x;
        right.push_back(x);
    }
    vector<int> temp;
    vector<int> arr= merge(left, right, n, m, temp);
    for(int i = 0; i < m + n; i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
