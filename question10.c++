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
    int size;
    //cout<<"Enter size of array "<<endl;
    //cin>>size;
    int a[] = {1,2,3,4,5,6};
    fun_print(a, 6); 
    return 0;
}
