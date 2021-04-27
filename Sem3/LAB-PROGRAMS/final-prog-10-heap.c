
#include <stdio.h>
#define MAX_SIZE 10
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int heap[], int size, int i)
{
  if (size < 0)
  {
    printf("No elements in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && heap[l] > heap[largest])
      largest = l;
    if (r < size && heap[r] > heap[largest])
      largest = r;
    if (largest != i)
    {
      swap(&heap[i], &heap[largest]);
      heapify(heap, size, largest);
    }
  }
}
void insert(int heap[], int newNum)
{
  if (size == 0)
  {
    heap[0] = newNum;
    size += 1;
  }
  else
  {
    heap[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(heap, size, i);
    }
  }
}
void deletemax(int heap[])
{
  if(size <= 0){
    printf("Underflow \n");
  }
  else{
    swap(&heap[0], &heap[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(heap, size, i);
    }
  }
}

void display(int heap[], int size)
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
                if(count < MAX_SIZE){
                    int el;
                    count += 1;
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
                if(count < 0){
                    printf("Underflow \n");
                }
                else{
                    deletemax(heap);
                }
                break;
            }
            case 3:{
                display(heap, size);
                break;
            }
            default :
                printf("Wrong option !");
        }
    }
    return 0;
}