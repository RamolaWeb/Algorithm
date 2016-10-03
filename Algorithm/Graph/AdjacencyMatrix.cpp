#include <stdio.h>
#define MAX 100

int main(){
	int adj[MAX][MAX];
    int n,max_edges,i,j,origin,destination,graph_type;
    printf("Enter 1 for Directed Type Graph and 2 for Undirected Type Graph\n");
    scanf("%d",&graph_type);
    printf("Enter Number of Edges \n");
    scanf("%d",&n);
    if(graph_type==1)
    max_edges=n*(n-1);
    else if(graph_type==2)
    max_edges=n*(n-1)/2;
    
    for(i=1;i<=max_edges;i++){
    	printf("Enter the edge %d(-1,-1 to quit)\n",i);
    	scanf("%d %d",&origin,&destination);
    	if(origin==-1&&destination==-1)
    	break;
    	if(origin<0||origin>n||destination<0||destination>n){
    		printf("Invalid Vertex\n");
    		i--;
    		
		}
		else{
			adj[origin][destination]=1;
			if(graph_type==2)
			adj[destination][origin]=1;
			
		}
	}
	for(i=0;i<=n-1;i++){
	for(j=0;j<=n-1;j++){
			printf("%d\t",adj[i][j]);
	}
     printf("\n");	
	}
	
	
	return 0;
}
