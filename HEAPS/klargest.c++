#include <iostream>
#include <vector>
#include<cstring>
#include<string>
using namespace std;
template < typename T >
class MaxHeap {
    private:
    //percolateUp()t is meant to restore the
    //heap property going up from a node to the root.
    void percolateUp(int i) {
        if(i <= 0)
        return;
        else if(h[parent(i)] < h[i]){
        swap(h[i], h[parent(i)]);
        percolateUp(parent(i));
        }
    }
    void maxHeapify(int i) {
        int lc = lchild(i);
        int rc = rchild(i);
        int imax = i;
        if(lc < size() && h[lc] > h[imax])
        imax = lc;
        if(rc < size() && h[rc] > h[imax])
        imax = rc;
        if(i != imax){
        swap(h[i], h[imax]);
        maxHeapify(imax);
        }
    }
    public:
    vector < T > h;
    inline int parent(int i) {
        return (i - 1) / 2;
    }
    inline int lchild(int i) {
        return i * 2 + 1;
    }
    inline int rchild(int i) {
        return i * 2 + 2;
    }
    MaxHeap() {
        h.resize(0);
    }
    int size() {
        return h.size();
    }
    T getMax() {
        if (size() <= 0){
        return -1;
    }
    else
        return h[0];
    }
    void insert(const T & key) {
    // Push elements into vector from the back
        h.push_back(key);
    // Store index of last value of vector in variable i
        int i = size()-1;
    // Restore heap property
        percolateUp(i);
    }
    void removeMax() {
        if(size() == 1){
    // Built-in function in STL which swaps the value of two variables
        h.pop_back();
        }
        else if(size() > 1){
        swap(h[0], h[size()-1]);
    // Deletes last element
        h.pop_back();
    // Restore heap property
        maxHeapify(0);
        }
        else
        return;
    }
    void buildHeap(T arr[], int size){
    // Copy elements of array into vector h
        copy(&arr[0], &arr[size], back_inserter(h));
        for (int i = (size - 1)/2; i >= 0; i--){
        maxHeapify(i);
        }
    }
    void printHeap(){
        for(int i = 0; i <= size()-1; i++){
        cout << h[i] << " ";
        }
        cout << endl;
    }
};
vector<int> findKLargest(int arr[], int size, int k){
    vector<int> output;
    MaxHeap<int> maxheap;
    for(int i = 0; i < size; i++){
        maxheap.insert(arr[i]);
    }
    while(k--){
        output.push_back(maxheap.getMax());
        maxheap.removeMax();
    }
    return output;
}
int main(){ 
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr[i] = x;
    }
    int k;
    cin>>k;
    //cout<<endl;
    vector<int> output = findKLargest(arr, n, k);
    for(int i = 0; i < output.size() - 1; i++){
        cout<<output[i]<<",";
    }
    cout<<output[output.size()-1]<<endl;
    return 0;
}