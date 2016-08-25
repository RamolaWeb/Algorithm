#include <stdio.h>
#include <stdlib.h>
void push(int);
int pop();
int top();
void display();

struct node{
	int data;
	struct node *link;
}*rear=NULL,*front=NULL;

int main(){
	int data,item,choice=-1;
	while(1){
		printf("1. Push The Element \n");
		printf("2. Pop The Element \n");
		printf("3. Get The Top Element \n");
		printf("4. Get All Element \n");
		printf("5. Exit \n");
		printf("Enter The Choice \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the Element \n");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
			   printf("The Element is %d \n",pop());
			   break;
			case 3:
			   	 printf("The Top Element is %d \n",top());
			   break;
			case 4:
			      display();
			      break;
			case 5:
			   exit(1);
			   break;
			      
		}
	}
	return 0;
}

void push(int data){
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=NULL;
	if(front==NULL)
	front=tmp;
	else
	rear->link=tmp;
	rear=tmp;
}

int pop(){
	struct node *tmp;
	int data;
	tmp=front;
	data=front->data;
	front=front->link;
	free(tmp);
	return data;
}

void display(){
	struct node *ptr=front;
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
}

int top(){
	return front->data;
}


