// C++ program for building Heap from Array 

#include <stdio.h> 
#define MAX_SIZE 20 
int count = -1;
int heap[MAX_SIZE];

//consider 0 as the starting index, thus left child is at position 2*i + 1 right child is at 2*i + 2

void maxheapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2 * i + 1;  
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 
	if (largest != i) { 
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
		maxheapify(arr, n, largest); 
	} 
} 

void buildHeap(int arr[], int n) 
{ 
	int startIdx = (n / 2) - 1; 
	for (int i = startIdx; i >= 0; i--) { 
		maxheapify(arr, n, i); 
	} 
} 

void display(int arr[], int n) 
{ 

	for (int i = 0; i <= n; ++i) 
		printf("%d " ,  arr[i]); 
	printf("\n"); 
} 
void dltelement(int arr[], int& n) 
{ 
   
    int lastElement = arr[n - 1]; 
    arr[0] = lastElement; 
    n = n - 1; 
    maxheapify(arr, n, 0); 
} 


int main(){
    int ch;
      printf("\n 1.Insert \n 2.Delete \n 3.Display \n\n");
    while(1){
        printf("Enter the option : ");
        scanf("%d", &ch);
        switch(ch){
        
            case 1:{
                if(count < MAX_SIZE){
                    int el;
                    printf("Enter element : ");
                    scanf("%d", &el);
                    count += 1;
                    heap[count] = el;
                    buildHeap(heap, count);
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
                    dltelement(heap, count);

                }
                break;
            }
            case 3:{
                if(count < 0){
                    printf("No elements in the max heap \n");
                }
                else{
                    display(heap, count);
                }
                break;
            }
            default :
                printf("Wrong option !");
        }
    }
    return 0;
} 
