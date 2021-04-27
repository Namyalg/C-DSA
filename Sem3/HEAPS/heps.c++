// C++ program for building Heap from Array 

#include <iostream> 

using namespace std; 
int count = 0;
int heap[5] = {0, 0, 0, 0, 0};
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2 * i + 1;  
	int r = 2 * i + 2; 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

void buildHeap(int arr[], int n) 
{ 
	int startIdx = (n / 2) - 1; 
	for (int i = startIdx; i >= 0; i--) { 
		heapify(arr, n, i); 
	} 
} 

void printHeap(int arr[], int n) 
{ 
	cout << "Array representation of Heap is:\n"; 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 
void deleteRoot(int arr[], int& n) 
{ 
   
    int lastElement = arr[n - 1]; 
    arr[0] = lastElement; 
    n = n - 1; 
    heapify(arr, n, 0); 
} 
// Driver Code 
int main() 
{ 
	int arr[] = { 1, 103, 25, 14, 6, }; 

	int n = sizeof(arr) / sizeof(arr[0]); 
   
    for(int i = 0; i < n; i++){
        count += 1;
		heap[i]= arr[i];
        buildHeap(heap, i);
		//heapify(heap, n, i); 
	    printHeap(heap, count); 
    }
	deleteRoot(heap, count);
	printHeap(heap, count);
	return 0; 
} 
