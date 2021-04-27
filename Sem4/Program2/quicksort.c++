#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition_index(int arr[], int l, int r, int pivot);
void swap(int *a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int arr[], int l, int r){
    if(l >= r){
        return;
    }

    int pivot = arr[l];
    cout<<"pivot value is "<<pivot<<endl;
    int pindex = partition_index(arr, l, r, pivot);

    quicksort(arr, l, pindex-1);
    quicksort(arr, pindex, r);
}


int partition_index(int arr[], int l, int r, int pivot){
    while(l < r){
        while(arr[l] < pivot){
            l += 1;
        }
        while(arr[r] >= pivot){
            r -= 1;
        }
        if(l < r){
           swap(&arr[l], &arr[r]);
           l += 1;
           r -= 1; 
        
        }
    }
    swap(&arr[l], &pivot);
    return l;
}

int arr[5] = {4, 21, 9, 12, 2};
int main(){
    //call quicksort
    //partition and get the index and call quicksort on it
    //the partitions based on the position of the number that has been returned
    quicksort(arr, 0, 4);
    
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}
