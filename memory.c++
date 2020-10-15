#include<bits/stdc++.h>

//PRESENT IN stdlib in C


using namespace std;

int main(){

    //malloc allocates the memory as a block,as a single block
    //just allocates the memory, the value is a garbage thing
    

    //calloc allocates memory again, but sets n blocks of memory
    //it sets the values to ZERO (though in c++ values are set to 0 in both)

    //realloc sets the size of a pointer to a greater or lesser size, contents will be copied if it goes to another location
    //if size is reduced the values are also lost

    //free used to free the pointer , important to avoid memory leaks or dangling pointers

    int* var = (int *)malloc(sizeof(int));
    int* varq = (int *)calloc(1, sizeof(int));
    cout<<"malloc " <<*var<<endl;
    cout<<"calloc " <<*varq<<endl;
    *var = 90;
    cout<<"mallocs place "<<var<<endl;
    cout<<"callocs place "<<varq<<endl;
    free(var);
    free(varq);
    int l;
    cout<<"Enter len "<<endl;
    cin>>l;
    int *arr = (int*)malloc(l*sizeof(int));
    for(int i= 0; i < l; i++){
        int el;
        cout<<"enter element ";
        cin>>el;
        *(arr + i) = el;
    }
    arr = (int*)realloc(arr, (l-3)*sizeof(int));
    for(int i = 0;i < l-3; i++){
        cout<<(arr + i)<<" ";
    }
    free(arr);
    return 0;
}
