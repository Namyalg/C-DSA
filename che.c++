
#include <bits/stdc++.h>

using namespace std;

 
int main(){ 
    int t;
    cin>>t;
    for(int i= 0;i<t;i++){
        int a;
        cin>>a;
        int ar[a][a];
        for(int j=0;j<a;j++){
            for(int g=0;g<a;g++){
                cin>>ar[i][j];
            }
        }
        for(int j=0;j<a;j++){
            for(int g=0;g<a;g++){
                if (ar[i][j] > ar[j][i]){
                    int t = ar[j][i];
                    ar[j][i] = ar[i][j];
                    ar[i][j] = t;
                }
            }
        }
        for(int j=1;j<=a;j++){
            for(int g=1;g<=a;g++){
                cout<<ar[i][j]<<" ";

            }
            cout<<endl;

        }
    }
    return 0;
}

     
