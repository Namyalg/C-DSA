#include<bits/stdc++.h>

using namespace std;



void fun_print(int arr[] , int size){
    int last = size-1;
    int front = 0;
    for(int i = 0; i < size; i++){
        if (i & 1){
            cout<<arr[front]<<" " ;
            front += 1;
        }
        else{
            cout <<arr[last]<<" ";
            last -= 1;
        }
    }
    cout<<endl;

}



int main() {
    int a[] = {5,4,3,2,1,-4940,830,4303,39303,393,393,-39,393,91,302,-29,-3930,-390,9303,-930,-3930};
    sort(a, a+20);
    return 0;
}
