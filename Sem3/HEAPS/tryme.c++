#include <iostream>
#include <vector>
#include<cstring>
#include<string>
using namespace std;
//vector<int> h;
class maxToMin{
    public:
    vector<int> h;
    
    maxToMin(vector <int> maxHeap){
        for(int i = 0; i < maxHeap.size(); i++){
            h.push_back(maxHeap[i]);
        }
    }
    inline int lchild(int i){
        return i*2 + 1;
    }
    inline int rchild(int i){
        return i*2 + 2;
    }
    void minHeapify(int i){
        int lc = lchild(i);
        int rc = rchild(i);
        int imin = i;
        if(lc < h.size() && h[lc] < h[imin])
        imin = lc;
        if(rc < h.size() && h[rc] < h[imin])
        imin = rc;
        if(i != imin){
        swap(h[i], h[imin]);
        minHeapify(imin);
        }
    }
    void print(){
        for(int i = 0; i < h.size(); i++){
            cout<<h[i]<<" ";
        }
        cout<<endl;
    }
};
string convertMax(vector<int> maxHeap){
    string result = "";
    maxToMin object(maxHeap);
    for(int i = (object.h.size() - 1)/2 ; i >= 0; i--){
        object.minHeapify(i);
    }
    for(int i = 0; i < object.h.size() - 1; i++){
        result += to_string(object.h[i])+ ",";
    }
    result += to_string(object.h.size());
    return result;
}
int main(){
    vector<int> h;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        h.push_back(x);
    }
    maxToMin obj(h);
    cout<<convertMax(obj.h)<<endl;
    return 0;

}
