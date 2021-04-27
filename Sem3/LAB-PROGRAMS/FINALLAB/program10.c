#include <stdio.h>
#define MAX_SIZE 10
int size = 0;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int heap[], int i)
{
  if (size < 0)
  {
    printf("No elements in the heap");
  }
  else
  {
    //Index starts from 0
    int largest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    //check if children are greater than parent
    if (lchild < size && heap[lchild] > heap[largest])
      largest = lchild;
    if (rchild < size && heap[rchild] > heap[largest])
      largest = rchild;

    if (largest != i)
    {
      swap(&heap[i], &heap[largest]);
      heapify(heap, largest);
    }
  }
}

void insert(int heap[], int val)
{
  if (size == 0)
  {
    heap[0] = val;
    size += 1;
    printf("The value added is %d \n", val);
  }
  else
  {
    //bottom up approach
    //el is added to the last and up heapify
    heap[size] = val;
    size += 1;
    printf("The value added is %d \n", val);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(heap, i);
    }
  }
}

void deletemax(int heap[])
{
  if(size <= 0){
    printf("No elements in the heap \n");
  }
  else{
    //top down approach
    printf("The element deleted is %d \n", heap[0]);
    swap(&heap[0], &heap[size - 1]);
    size -= 1;
    heapify(heap, 0);
  }
}

void display(int heap[])
{
  if(size <= 0){
    printf("No elements in the heap \n");
  }
  else{
    for (int i = 0; i < size; ++i)
      printf("%d ", heap[i]);
    printf("\n");
  }
}

int main()
{
   int heap[MAX_SIZE];
   int ch;
   int count = 0;
    while(1){
        printf("\n 1.Insert \n 2.Delete \n 3.Display \n\n");
        printf("Enter the option : ");
        scanf("%d", &ch);
        switch(ch){
        
            case 1:{
                if(size < MAX_SIZE){
                    int el;
                    printf("Enter element : ");
                    scanf("%d", &el);
                    insert(heap, el); 
                   
                }
                else{
                    printf("Overflow \n");
                }
                break;
            }
            case 2:{
              deletemax(heap);
              break;
            }
            case 3:{
                display(heap);
                break;
            }
            default :
                printf("Wrong option !");
        }
    }
  return 0;
}