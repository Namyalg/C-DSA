#include<stdio.h>


void dfs(int a[10][10],int n,int visited[10],int current)
{
	int j;
	
	visited[current]=1;
	printf("%d ",current);     
	for (j=0;j<n;j++)
	{
		if (a[current][j]==1 && visited[j]==0)      //current to j and j is not yet visited
		{
			dfs(a,n,visited,j);
		}
	}
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
	         if (visited[i]==0)
		 {
				dfs(a,n,visited,i);
				comp++;
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

	return 0;
}