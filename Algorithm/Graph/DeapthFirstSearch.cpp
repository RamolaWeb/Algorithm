#include <stdio.h>
#define INITIAL 1
#define VISITED 2
#define MAX 100
#define NIL -1
int predecessor[MAX];
int adj[MAX][MAX];
int n;
int stack[MAX];
int top=-1;
int state[MAX];
void create_graph();
int isEmpty();
void push(int element);
int pop();
void dfs();
void dfs_transversal(int);

int main(){
	create_graph();	
	dfs();
	return 0;
}

void dfs(){
	for(int i=0;i<n;i++){
		state[i]=INITIAL;
		predecessor[i]=NIL;
	}
	int starting_vertex;
	printf("Enter The Starting Vertex \n");
	scanf("%d",&starting_vertex);
	dfs_transversal(starting_vertex);
	for(int i=0;i<n;i++){
		if(state[i]==INITIAL)
		dfs_transversal(i);
	}
	
}

void dfs_transversal(int starting_vertex){
	push(starting_vertex);
	int v;
	while(!isEmpty()){
		v=pop();
		if(state[v]==INITIAL){
			printf("%d\t",v);
			state[v]=VISITED;
		}
		for(int i=0;i<n;i++){
			if(adj[v][i]==1){
				if(state[i]==INITIAL){
				push(i);
				predecessor[i]=v;
				}
				else if(state[i]==VISITED){
					printf("Back Edge from %d to %d \n",i,v);
				}
				
			}
		}
	}
	printf("\n");
}

void create_graph(){
	printf("Enter The Number of Vertex \n");
	scanf("%d",&n);
	int graph_edges=n*(n-1),source,destination;
	for(int i=0;i<graph_edges;i++){
		printf("Enter The Source and Destination for the  edge %d (-1,-1) to quit \n",i);
		scanf("%d %d",&source,&destination);
		if(source==-1&&destination==-1)
		break;
		if(source<0||source>n||destination<0||destination>n)
		{
			printf("Invalid Edge \n");
			i--;
		}
		else{
			adj[source][destination]=1;
		}
	}
}

void push(int element){
	if(top!=MAX-1)
	{
		top+=1;
		stack[top]=element;
	}
}
int pop(){
	if(!isEmpty()){
		int data=stack[top];
		top-=1;
		return data;
	}
	return -1;
}
int isEmpty(){
	if(top==-1)
	return 1;
	return 0;
}

