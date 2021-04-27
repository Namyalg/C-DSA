#include <iostream>
#include "unordered_set"
#include<unordered_set>
using namespace std;

int* findSum(int arr[], int sum, int size, int pair[]) { 
    unordered_set<int> elements;
    for(int i = 0 ; i < size; i++){
        elements.insert(arr[i]);
    }
    int flag = 0;
    for(int i = 1; i < size; i++){
        int diff = sum - arr[i];
        if(elements.find(diff) != elements.end() and diff != arr[i]){
            pair[0] = arr[i];
            pair[1] = diff;
            flag = 1;
            //cout<<pair[0]<<" "<<pair[1]<<endl;
            //return pair;
        }
        else{
            continue;
        }
    }
    if(flag){
        return pair;
    }
    else{
        return arr;
    }

}

int main(){
    int size;
    cin>>size;
    int arr[size];
    int pair[2] = {0,0};
    for(int i = 0; i < size; i++){
        int x;
        cin>>x;
        arr[i] = x;
    }
    int sum;
    cin>>sum;
    int* pairsum =  findSum(arr, sum, size, pair); 
    size = sizeof(pairsum)/sizeof(pairsum[0]);
    cout<<"size is "<<size<<endl;
    for(int i = 0; i < size; i++){
            cout<<pairsum[i]<<" ";
    }
    /*size = sizeof(pairsum)/sizeof(pairsum[0]);
    cout<<"size is"<<size<<endl;
    if(size == 2){
        cout<<"Number 1"<<pairsum[0]<<endl;
        cout<<"Number 2"<<pairsum[1]<<endl;
        cout<<"Sum "<<sum<<endl;
    }
    else{
        for(int i = 0; i < size; i++){
            cout<<pairsum[i]<<" ";
        }
    }*/
    return 0;
}