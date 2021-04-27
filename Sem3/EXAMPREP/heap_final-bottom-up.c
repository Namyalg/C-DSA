#include<stdio.h>
#define size 15

// void swap(int i, int largest, int arr[MAXSIZE]){
//     int t = arr[largest];
//     arr[largest] = arr[i];
//     arr[i] = t;
// }

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int heap[], int i, int c)
{
  
    //Index starts from 0
    int largest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    //check if children are greater than parent

    //here the lchild and rchild indices must be less than the count of nodes
    //as else it will access a null value and will give a wrong value as the answer
    
    if (lchild < c && heap[lchild] > heap[largest] )
      largest = lchild;
    if (rchild < c && heap[rchild] > heap[largest])
      largest = rchild;

    //this is for the minheap, as else the value 0 will be taken if the value is not present
    // if (lchild < size && heap[lchild] != 0 && heap[lchild] < heap[largest] )
    //   largest = lchild;
    // if (rchild < size &&  heap[rchild] != 0  && heap[rchild] < heap[largest])
    //   largest = rchild

    if (largest != i)
    {
      swap(&heap[i], &heap[largest]);
      heapify(heap, largest, c);
    }
  
}

//main heapify function 
// void heapify(int arr[MAXSIZE], int i){
//     int smallest = i;
//     int lchild = 2*i + 1;
//     int rchild = 2*i + 2;

//     //change > than to less than to convert to min heap
//     if(lchild < MAXSIZE && arr[lchild] < arr[smallest]){
//         smallest = lchild;
//     }
//     if(rchild < MAXSIZE && arr[rchild] < arr[smallest]){
//         smallest = rchild;
//     }
//     if(smallest != i){
//         swap(&arr[i], &arr[smallest]);
//         heapify(arr, smallest);
//     }
    
// }
int main(){
    //bottom up heap construction this is
    int c = 8;
    int* cnt = &c;
    int a[size] = {2, 9, 7, 6, 5, 8, -10, 100};

    //printf("Enter the elements of the array \n");
    for(int i = c / 2; i >= 0; i--){
        heapify(a, i, c);
    }
    for(int i = 0; i < c; i++){
        printf("%d ", a[i]);
    }
    int x = 4;
    return 0;
}