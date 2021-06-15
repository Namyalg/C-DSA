#include<stdio.h>

void swap(int* a, int*b){
    int t = *a;
    *a = *b;
    *b = t;
}
int n = 7;
//make a max heap
int heap[7] = {9, 3, 13, 19, 2, 44, 12};
void heapify(int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && heap[largest] > heap[l]){
        largest = l;
    }
    if(r < n && heap[largest] > heap[r]){
        largest = r;
    }
    if(largest != i){
        swap(&heap[largest], &heap[i]);
        heapify(largest);
    }
}

int dlt(){
    int max = heap[0];
    heap[0] = heap[n-1];
    n -= 1;
    heapify(0);
    return max;
}

int main(){
    
    //use the heapification approach and then
    //delete the max element every single time
    //and heapify from the root every time
    for(int i = 3; i >= 0; i--){
        heapify(i);
    }
    int srtd[n] = {-1};
    int r = 0;
    for(int i = n-1; i >= 0; i--){
        srtd[r++] = dlt();
    }
    printf("\nThe sorted array is \n");
    for(int i = 0; i < r; i++){
        printf("%d ", srtd[i]);
    }
    return 0;
}