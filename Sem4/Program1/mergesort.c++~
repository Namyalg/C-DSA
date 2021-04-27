#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int arr[] = {1,2,3,4,5,6};

void mergesort(int arr[], int l, int r){
    if(l > r){
        return;
    }
    mergesort(arr, l, mid);
    mergesort(arr, mid, r);
    merge(arr, l, r);

}



void merge(int arr[], int n, int m){
    int mid = (l + r) / 2;
    int left[mid - l + 1];
    int right[r - mid];
   
    for(int i = l; l <= mid; l++){
        left[i] = arr[i];
    }
    for(int j = mid + 1; j < r; j++){
        right[j] = arr[j];
    }
    int l = 0, r = 0;
    int k = 0;
    while(l < n && r < m){
        if(left[l] < right[r]){
            arr[k++] = left[l++];
        }
        else{
            arr[k++] = right[r++];
        }
    }
    while(l < n){
        arr[k++] = left[l++];
    }
    while(r < m){
        arr[k++] = right[r++];
    }
 
}

int main(){
    int ls = 0, rs = 6;
    /*
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
    }*/

    mergesort(arr, ls, rs);
	return 0;
}
