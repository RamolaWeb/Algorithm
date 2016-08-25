#include <stdio.h>
#include <stdlib.h>

void push(int);
int sum(int);
int display();
void deleteAll();

struct node{
	int priority;
	struct node *link;
}*front=NULL;

int main(){
	int no,i;
	scanf("%d",&no);
	while(no!=-1){
		int data,avg,sum1=0;
		for(i=0;i<no;i++)
		{
			scanf("%d",&data);
			push(data);
		}
		sum1=display();
	if(sum1%no==0){
		avg=sum1/no;
		printf("%d\n",sum(avg));
		
	}
	else{
		
		printf("%d\n",-1);
	}	
	while(no--)
		deleteAll();
	scanf("%d",&no);	
	}
}

void push(int priority){
	struct node *tmp=(struct node *) malloc(sizeof(struct node)),*ptr;
	tmp->priority=priority;
	if(front==NULL||priority>front->priority)
	{
		tmp->link=front;
		front=tmp;
	}
	else{
		ptr=front;
		while(ptr->link!=NULL&&ptr->link->priority<=priority)
		ptr=ptr->link;
		tmp->link=ptr->link;
		ptr->link=tmp;
	}
}
int display(){
	struct node *ptr=front;
	int sum=0;
	while(ptr!=NULL){
		sum+=ptr->priority;
		ptr=ptr->link;
	}
	return sum;
}

int sum(int avg){
	struct node *ptr=front;
	int count=0;
	while(ptr!=NULL&&ptr->priority>avg){
		count+=(ptr->priority-avg);
		ptr=ptr->link;
	}
	return count;
}

void deleteAll(){
	struct node *ptr=front;
	front=front->link;
	free(ptr);
}


