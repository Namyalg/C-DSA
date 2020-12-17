#include<bits/stdc++.h>

using namespace std;

int* removeEven(int Arr[] , int size){
    //vector<int> temp;
    static int temp[10000];
    int k =0;
    for(int i= 0;i < size; i++){
        if (Arr[i] & 1){
            temp[k] = (Arr[i]);
            k += 1;
        }
    }
    return temp;
        
}

int main() {
    int a[] = {1,2,3,4,5,6};
    int* d = removeEven(a , 6);
    cout << *(d+1);
    return 0;
}
