#include<bits/stdc++.h>

using namespace std;

    int* test () {
            int *c = new int[5];
            for (int i = 0; i < 5; i++) c[i] = i;
            return c;
    }
int main(){
    
    int la, lb;
    cout<<"Enter size of ar1, ar2"<<endl;
    cin>>la>>lb;
    int sa = 0;
    int sb = 0;
    int ind = 0;
    int a[la], b[lb];
    for(int i = 0;i < la; i++){
        int e;
        cin>>e;
        a[i] = e;
    }
    for(int i = 0;i < lb; i++){
        int e;
        cin>>e;
        b[i] = e;
    }
    int lc = la + lb;
    int *d = test();
    int* c;
    //int c[lc];
    for(int i= 0,j=0,k=0 ;i < lc; i++){
        if (j < la && k < lb){
        
            if (a[j] < b[k]){
                &(c + i) = a[j];
                j += 1;
            }
            else{
                c[i] = b[k];
                k += 1;
            }
        }
        else {
            ind = i;
            if (j == la) {
                sb = k;
                break;
            }
            else if(k == lb){
                sa = j;
                break;
            }
            /*int ind = i;
            if (j == la){
                for(int p = k; p <lb; p++){
                    c[ind] = b[p];
                    ind += 1;
                }
            }
            else if (k == lb){
                for(int p = j; p < la; p++){
                    c[ind] = a[p];
                    ind += 1;
                }
            }
        }*/
        
    }
}
    if (sa != 0){
        for(int i = sa, q=ind; i < la,q<lc ; i++,q++) {
            c[q] = a[i];
            //cout<<a[i]<< " ";
        }
    }
    else if(sb != 0){
        for(int i= sb,q=ind; i < lb,q<lc; i++,q++){
            c[q] = b[i];
            //cout<<b[i]<<" ";
        }
    }
    for(int z =0; z < lc;z++){
        cout<<c[z]<<" ";
    }
    cout<<endl;
    return 0;
}

