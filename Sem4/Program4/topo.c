#include<stdio.h>

int stack[100];
int top = -1;
int toposort[100];
int to = -1;
int st = 0;
int ct;
void dfs(int a[10][10], int n, int visited[10], int current, int tp[10])
{
	int j;
	stack[++top] = current;
	visited[current]=1;
	printf("%d ",current);     
	for (j=0;j<n;j++)
	{
		if (a[current][j]==1 && visited[j]==0)      //current to j and j is not yet visited
		{
			dfs(a,n,visited,j, tp);
		}
	}
    tp[ct++] = stack[top--];
}

void DFS(int a[10][10],int n)
{
  int visited[10],comp=0;

      for (int i=0;i<n;i++)
      {
	    visited[i]=0;
      }
	
	//To find DFS traversal 
	printf("DFS order:\n");
	
    
	for (int i=0;i<n;i++)
	{
        ct = 0;
        int tp[10];
	    if (visited[i]==0){
				
                dfs(a, n, visited, i, tp);
				comp++;
		 }
         for(int j = 0; j < ct; j++){
            toposort[++to] = tp[ct - j - 1];
         }			
	}

        if (comp > 1)
	{
              printf("\nThe graph is disconnected \n");
              printf("\nThe no. of components are:%d\n",comp);
        }
	else
	{
		printf("\nGraph is connected.\n");
	}

}






int main()
{
	//int a[5][5],n,i,j,comp=0;
	
    int graph[10][10];
    int n;
    printf("Enter the number of vertices \n");
    scanf("%d", &n);
	printf("%d", n);
	
    printf("Enter the graph in the form of a adjacncy matrix \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            scanf("%d", &x);
            graph[i][j]  = x;
            graph[j][i] = x;
        }
    }

    DFS(graph, n); 
    printf("\nThe topological sort order is \n");
    for(int i = 0; i <= to; i++){
        printf("%d ", toposort[i]);
    }
    



	return 0;
}