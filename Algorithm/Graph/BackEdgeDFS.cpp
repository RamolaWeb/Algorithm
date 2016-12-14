/*
In this Code we have discussed about the Deapth First Traversal of the graph .It also demostrated how to find the backedge 
of the graph to detect the cycle.It also show to create a spanning tree of the graph and to show wheather it is strongly 
connected or not.
*/
#include <stdio.h>
#define INITIAL 0
#define VISITED 1
#define MAX 100

int predecessor[MAX];
int status[MAX];
int adj[MAX][MAX];
int n,top=-1,t=-1;
int stack[MAX];

int pop();
void push(int);
void create_graph();
void dfs(int);
void deapth_traversal();
void reverseGraph();

int main(){
	create_graph();
	deapth_traversal();
	if(t){
		reverseGraph();
		deapth_traversal();
	}
	if(t){
		printf("Strongly Connected");
	}
	return 0;
}

void create_graph(){
	int choice,no_edges,i=0,source,destination;
	printf("Type 1 for the Undirected Graph and Type 2 for the Directed Graph:\n");
	scanf("%d",&choice);
	printf("Enter the Number of The Vertex:\n");
	scanf("%d",&n);
	if(choice==1)
	no_edges=(n*(n*2))/2;
	else
		no_edges=(n*(n*2));
	for(i=1;i<=no_edges;i++){
		printf("Enter the Source and destination for the edge %d (-1,-1 to quit): \n",i);
		scanf("%d",&source);
		scanf("%d",&destination);
		if(source==-1&&destination==-1)
		 break;
		else if(source<0||source>n||destination<0||destination>n){
			printf("Enter the correct Source and Destination\n");
			i--;
		} 
		else{
			adj[source][destination]=1;
			if(choice==1)
			adj[destination][source]=1;
		}
	}	
}

void push(int data){
	if(top==MAX-1){
		printf("Stack OverFlow\n");
		return;
	}
	top+=1;
	stack[top]=data;
}

int pop(){
	if(top==-1){
		printf("Stack UnderFlow\n");
		return -1;
	}
	int data=stack[top];
	top-=1;
	return data;
}

void deapth_traversal(){
	int source,i=0;
	printf("Enter The Source Vertex: \n");
	scanf("%d",&source);
	for(i=0;i<n;i++){
		status[i]=INITIAL;
		predecessor[i]=-1;
	}
	
	dfs(source);
	// if all the vertex are not reached by the vertex during dfs , it is not reacheable.
	for(i=0;i<n;i++){
		if(status[i]==INITIAL){
			t=0;
			printf("Not Strongly Connected\n");
			return;
		}
	}
	t=1;
	
	printf("Tree Edge : \n");
	for(i=0;i<n;i++){
		if(predecessor[i]!=-1){
			printf("Edge is from Vertex %d to Vertex %d \n",predecessor[i],i);
		}
	}
	
}

void dfs(int source){
	int v,i;
	push(source);
	while(top!=-1){
		v=pop();
		if(status[v]==INITIAL){
			printf("%d \t",v);
			status[v]=VISITED;
		}
		// we have store each adjacent vertex of the vertex which is not visited yet and mark them as predecessor.
		for(i=0;i<n;i++){
			if(adj[v][i]){
				if(status[i]==INITIAL){
					predecessor[i]=v;
					push(i);
					printf("Edge from %d to %d is Forward Edge \n",v,i);
				}
				else if(status[i]==VISITED){
						printf("Edge from %d to %d is Back Edge \n",v,i);
				}
			}
		}
	}
}

// for reversing the graph
void reverseGraph(){
	int newAdj[MAX][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			newAdj[i][j]=adj[j][i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i][j]=newAdj[i][j];
		}
	}
	
}





