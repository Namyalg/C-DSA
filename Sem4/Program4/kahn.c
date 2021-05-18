#include<stdio.h>

int main(){

    int graph[5][5];
    int n;
    printf("Enter the number of vertices \n");
    scanf("%d", &n);

    int indeg[n] = {0};
    int neighbours[n][5];
     for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            neighbours[i][j] = -1;
        }
        //printf("\n");
    }
    printf("Enter the directed graph \n");
    for(int i = 0; i < n; i++){
        int tp = 0;    
        for(int j = 0; j < n; j++){
            int x;
            scanf("%d", &x);
            if(x == 1){
                indeg[j] += 1;
                neighbours[i][tp++] = j;
            }    
        }
    }

     for(int i = 0; i < n; i++){
         printf("the neigbors of %d ", i);
        for(int j = 0; j < 5; j++){
            
            printf("%d ", neighbours[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){
        printf("The indegree of %d is %d \n", i, indeg[i]);
    }

    //maintain a queue to perform the removal

    int qu[n] = {-1};
    int idx = 0;
    int count = 0;
    int l = 0;
    for(int i = 0; i < n; i++){
        if (indeg[i] == 0){
            qu[idx++] = i;
            count += 1;
            l += 1;
        }
    }
    
    while(count > 0){
        int frnt = qu[0];
        for(int i = 0; i < l-1; i++){
            qu[i] = qu[i+1];
        }
        l -= 1;

        for(int j = 0; j < n; j++){
            indeg[neighbours[frnt][j]] -= 1;
            if(indeg[neighbours[frnt][j]] == 0){
                qu[idx]++ = neighbours[frnt][j];
            }
        }




    }



    return 0;
}