#include <stdio.h>
#define MAX 100

int quene[MAX];
int front=-1,rear=-1;
int adj[MAX][MAX];
int n;
int color[MAX];

void adjancencyMatrix();
void push(int data);
int pop();
void bipartition();

int main(){
	adjancencyMatrix();
	bipartition();
	return 0;
}

void adjancencyMatrix(){
	int choice,no_edjes,source,destination;
	printf("Press 1 for Undirected Graph and Press 2 for Directed Graph:\n");
	scanf("%d",&choice);
	printf("Type Number of the Vertex:\n");
	scanf("%d",&n);
	if(choice==1)
	no_edjes=(n*(n-1))/2;
	else
	no_edjes=(n*(n-1));
	for (int i=0;i<no_edjes;i++){
		printf("Type the source and destination respectively (-1,-1) to quit\n");
		scanf("%d",&source);
		scanf("%d",&destination);
		if(source==-1 && destination==-1)
		break;
		else if(source<0||source>n||destination<0||destination>n){
			i--;
			printf("Enter correct Edge\n");
		}
		else{
		   adj[source][destination]=1;
		   if(choice==1)
		   adj[destination][source]=1;
		}
		
	}
	
}

void push(int data){
if(rear==MAX-1){
	printf("OverFlow");
		return;
}
if(front==-1)
front+=1;
quene[rear]=data;
rear+=1;
}


int pop(){
	if(front==-1){
		printf("UnderFlow");
		return -1;
	}
	int data=quene[front];
	front-=1;
	return data;
	
}

void bipartition(){
	for(int i=0;i<n;i++){
			color[i]=-1;
	}

	int source,v,c=1;
	printf("Enter The Souce Vertex\n");
	scanf("%d",&source);
	push(source);
	color[source]=c;
	while(front!=-1){
		v=pop();
		c=1-color[v];
		for(int i=0;i<n;i++){
			if(adj[v][i]&&color[i]==-1){
				push(i);
				color[i]=c;
			}
			else if(adj[v][i]){
				if(color[v]==color[i]){
					printf("Not BIPARTITION\n");
					return;
				}
			}
		}
	}
	printf("Bipartion Possible\n");
}
