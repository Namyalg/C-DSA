#include <iostream>
#include <vector>
#include<cstring>
#include<string>
using namespace std;
vector<int> h;
inline int lchild(int i){
    return i*2 + 1;
}
inline int rchild(int i){
    return i*2 + 2;
}
 void minHeapify(int i, vector<int> maxHeap){
        int lc = lchild(i);
        int rc = rchild(i);
        int imin = i;
        if(lc < maxHeap.size() && maxHeap[lc] < maxHeap[imin])
        imin = lc;
        if(rc < maxHeap.size() && maxHeap[rc] < maxHeap[imin])
        imin = rc;
        if(i != imin){
        swap(maxHeap[i], maxHeap[imin]);
        minHeapify(imin, maxHeap);
        }
    }
string convertMax(vector<int> maxHeap){
    string result = "";
    //void minHeapify(int i);
   
    for(int i = maxHeap.size()/2; i >= 0; i--){
        minHeapify(i, maxHeap);
    }
    for(int i = 0; i< maxHeap.size() ; i++){
        cout<<maxHeap[i]<<" ";
        result + to_string(maxHeap[i]);
    }
    return result;
}
int main(){
    //vector<int> h;
    int n, m;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        h.push_back(x);
    }
    cout<<convertMax(h);
    return 0;

}
