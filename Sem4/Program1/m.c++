#include <iostream>
#include<stdlib.h>

using namespace std;

int merge(int arr[], int l, int m, int r, int count)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
        count += 1;
	}

	while (i < n1) {
        count += 1;
        arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
        count += 1;
		arr[k] = R[j];
		j++;
		k++;

	}
    return count;
}

int mergeSort(int arr[],int l,int r, int count){
	if(l < r){
	
	int m = l + (r - l)/2;
	mergeSort(arr, l, m, count);
	mergeSort(arr, m+1, r, count);
	count += merge(arr, l, m, r, count);
   
    }
    return count;
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

int count;

int main()
{
    for(int sz = 16; sz < 4096; sz = sz << 1){
        int ascend[sz], descend[sz], radom[sz];
        
        for(int i = 1; i <= sz; i++){
            ascend[i] = i;
            descend[i] = sz - i + 1;
            radom[i] = rand();
        }
        int c1 = 0, c2 = 0, c3 = 0;    
	    c1 = mergeSort(ascend, 0, sz - 1, c1);
	    c2 = mergeSort(descend, 0, sz - 1, c2);
	    c3 = mergeSort(radom, 0, sz - 1, c3);
        cout<<"       "<<c1<<" " <<c2<<" "<<c3<<endl;    
    }
    cout<<endl;
	int arr[] = { 1, 17, 89, 6, 7, 1023 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);
    mergeSort(arr, 0, 5, 0);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

