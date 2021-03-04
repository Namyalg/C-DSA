#include<stdio.h>
#define MAXSIZE 10
void swap(int i, int largest, int arr[MAXSIZE]){
    int t = arr[largest];
    arr[largest] = arr[i];
    arr[i] = t;
}


//main heapify function 
void heapify(int arr[MAXSIZE], int i, int c){
    if(i < c){
    int largest = i;
    int lchild = 2*i + 1;
    int rchild = 2*i + 2;

    //change > than to less than to convert to min heap
    if(lchild < MAXSIZE && arr[lchild] > arr[i]){
        largest = lchild;
    }
    if(rchild < MAXSIZE && arr[rchild] > arr[largest]){
        largest = rchild;
    }
    // if(lchild < MAXSIZE && arr[lchild] > arr[i]){
    //     largest = lchild;
    // }
    // if(rchild < MAXSIZE && arr[rchild] > arr[largest]){
    //     largest = rchild;
    // }
    if(largest != i){
        swap(i, largest, arr);
        heapify(arr, largest, c);
    }
    }
}

// void dlt(int arr[MAXSIZE], int* c){
//     arr[0] = arr[c-1];
//     arr[c-1] = 0;
//     c -= 1;
//     heapify(arr, 0, c);

// }

int main(){
    //bottom up heap construction this is
    int c = 8;
    int* cnt = &c;
    int a[MAXSIZE] = {2, 9, 7, 6, 5, 8, -10, 100};

    //printf("Enter the elements of the array \n");
    for(int i = MAXSIZE / 2; i >= 0; i--){
        heapify(a, i, c);
    }
    for(int i = 0; i < c; i++){
        printf("%d ", a[i]);
    }
    int x = 4;
    while(x--){
        a[0] = a[c-1];
        c -= 1;
        heapify(a, 0, c);
        printf("\n");
        for(int i = 0; i < c; i++){
            printf("%d ", a[i]);
        }
    }
    // dlt(a, c);
    // printf("\n");
    // for(int i = 0; i < c; i++){
    //     printf("%d ", a[i]);
    // }
    //  dlt(a, c);
    // printf("\n");
    // for(int i = 0; i < c; i++){
    //     printf("%d ", a[i]);
    // }
    return 0;
}