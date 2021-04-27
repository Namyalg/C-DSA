#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> a;
    int y;
    cout<<"enter number of elements"<<endl;
    cin>>y;
    while(y--) {
        int k;
        cin>>k;
        a.emplace_back(k);
    }
    int temp;
    for (int i = 0 ;i < a.size(); i++){
        for(int j = i; j < a.size(); j++){
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (const int x: a) {
        cout << x <<" ";
    }
}
