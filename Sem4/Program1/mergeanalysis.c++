#include <iostream>
#include<stdlib.h>

using namespace std;

int count;
void merge(int arr[], int l, int m, int r)
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
        arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;

	}
}

void mergeSort(int arr[],int l,int r){
	if(l < r){
	
	int m = l + (r - l)/2;
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);
   
    }
}


int main()

{
    cout<<"     Ascending    Descending  Random"<<endl;
    for(int sz = 16; sz < 4096; sz = sz << 1){
        int ascend[sz], descend[sz], radom[sz];
        
        for(int i = 1; i <= sz; i++){
            ascend[i] = i;
            descend[i] = sz - i + 1;
            radom[i] = rand();
        }
        cout<<sz<<"    ";
        int c1 = 0, c2 = 0, c3 = 0;    
	    count = 0;
        mergeSort(ascend, 0, sz - 1);
        cout<<count<<"             ";
        count = 0;
	    mergeSort(descend, 0, sz - 1);
        cout<<count<<"         ";
        count = 0;
	    mergeSort(radom, 0, sz - 1);
        cout<<count<<endl;    
    }
    cout<<endl;
	int arr[] = { 1, 17, 89, 6, 7, 1023 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout<<"The array before sorting is "<<endl;
    for(int i = 0; i < arr_size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, 0, 5);
	cout << "\nSorted array is \n";
	for(int i = 0; i < arr_size; i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}

