#include <stdio.h>
#define MAX 100
#define INITIAL 0
#define WAITING 1
#define VISITED 2

int adj[MAX][MAX];
int state[MAX],quenue[MAX],front=-1,rear=-1;
int n;

void printAdj();
void create_graph();
void BFS();
void bfs_transversal(int starting_vertex);
int isEmpty();
int delete_quenue();
void insert(int element);
int main(){
	create_graph();
	printAdj();
	BFS();
	return 0;
}

void create_graph(){
	int graph_edges,origin,destination;
	printf("Enter The Number of Vertices \n");
	scanf("%d",&n);
	graph_edges=n*(n-1);
	
	for(int i=0;i<=graph_edges;i++){
		printf("Enter the Edge %d (-1,-1)\n",i);
		scanf("%d %d",&origin,&destination);
		if(origin==-1&&destination==-1)
		break;
		if(origin<0||origin>n||destination<0||destination>n){
			printf("Invalid Vertex\n");
			i--;
		}
		else{
			adj[origin][destination]=1;
		}
	}
	
}

void BFS(){
	for(int i=0;i<n;i++)
	state[i]=INITIAL;
	
	int starting_vertex;
	printf("Enter The Starting Vertex \n");
	scanf("%d",&starting_vertex);
	bfs_transversal(starting_vertex);
	
}

void bfs_transversal(int starting_vertex){
	insert(starting_vertex);
	state[starting_vertex]=WAITING;
	while(!isEmpty()){
		int data=delete_quenue();
		state[data]=VISITED;
		printf("%d \t",data);
		for(int i=0;i<n;i++){
			if(adj[data][i]==1&&state[i]==INITIAL)
			{
				insert(i);
				state[i]=WAITING;
			}
		}
	}
	
}


int isEmpty(){
	if(front==-1||front==rear+1)
	return 1;
	return 0;
}

int delete_quenue(){
	if(isEmpty())
	{
		printf("UnderFlow \n");
		return -1;
	}
	
	int data=quenue[front];
	front+=1;
	return data;
	
}

void insert(int element){
	if(rear==MAX-1)
	{
		printf("OverFlow\n");
	}
	
	if(front==-1)
	 front=0;
	rear=rear+1;
	quenue[rear]=element; 
}

void printAdj(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			printf("%d \t",adj[i][j]);
		}
		printf("\n");
	}
}
