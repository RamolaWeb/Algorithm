#include <stdio.h>
#define TEMP 0
#define PERM 1
#define MAX  1000
#define INFINITY 999999
#define NIL -1

int adj[MAX][MAX];
int status[MAX];
int pathlength[MAX];
int predecessor[MAX];
int n;

void create_graph();
void dijkstra(int s);
int minPathlength();
void pathLength(int s,int v);

int main(){
	int source;
	create_graph();
	printf("Enter The Source Vetex \n");
	scanf("%d",&source);
	dijkstra(source);
	
	while(1){
		int destination;
		printf("Enter The Destination Vertex (-1 to exit)\n");
		scanf("%d",&destination);
		if(destination==-1)
		break;
		else if(destination<0){
			printf("Wrong Destination Vertex \n");
		}
		else{
		pathLength(source,destination);
		}
	}
	
	return 0;
}

void dijkstra(int s){
	int current;
	for(int i=0;i<n;i++){
		status[i]=TEMP;
		pathlength[i]=INFINITY;
		predecessor[i]=NIL;
	}
	
	pathlength[s]=0;
	
	while(1){
		current=minPathlength();
		if(current==NIL)
		return;
		status[current]=PERM;
		
		for(int i=0;i<n;i++){
			if(status[i]==TEMP&&adj[current][i]!=0){
				if(pathlength[current]+adj[current][i]<pathlength[i]){
					pathlength[i]=pathlength[current]+adj[current][i];
					predecessor[i]=current;
				}
			}
		}
	} 
	 
	 
}

int minPathlength(){
	int min=INFINITY,k=NIL;
	for(int i=0;i<n;i++){
		if(status[i]==TEMP&&pathlength[i]<INFINITY){
			min=pathlength[i];
			k=i;
		}
	}
	return k;
}

void pathLength(int s,int v){
	int path[MAX];
	int count=0,k;
	int shortest_length=0;
	while(v!=s){
		count++;
		k=predecessor[v];
		path[count]=v;
		shortest_length+=adj[k][v];
		v=k;
	}
	count++;
	path[count]=s;
	for(int i=count;i>1;i--){
		printf("%d-->",path[i]);
	}
	printf("%d \t",path[1]);
	printf("The Shortest Path Length is %d \n",shortest_length);
}



void create_graph(){
	printf("Enter The Number of Vertex \n");
	scanf("%d",&n);
	int graph_edge=n*(n+1),source,destination;
	
	for(int i=0;i<graph_edge;i++){
		printf("Enter The Source and Destination (-1,-1) to quit \n");
		scanf("%d %d",&source,&destination);
		if(source==-1&&destination==-1)
		  break;
		else if(source<0||source>n||destination<0||destination>n){
			printf("Wrong Source And Destiantion\n");
			i--;
		}  
		else{
			int weight;
			printf("Enter The Weight of Edge \n");
			scanf("%d",&weight);
			adj[source][destination]=weight;
		}
	}
}


