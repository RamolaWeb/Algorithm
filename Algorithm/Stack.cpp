#include <stdio.h>
#include <stdlib.h>
void push(char);
char pop();
char Top();
void display();

struct node{
	char data;
	struct node *link;
}*top=NULL;

int main(){
	int item,choice=-1;
	char data;
	while(1){
		printf("1. Push The Element \n");
		printf("2. Pop The Element \n");
		printf("3. Get The Top Element \n");
		printf("4. Display All Element\n");
		printf("Enter The Choice \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the Element \n");
				scanf(" %c",&data);
				push(data);
				break;
			case 2:
			   printf("The Element is %c \n",pop());
			   break;
			case 3:
			   	 printf("The Top Element is %d \n",Top());
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

void push(char data){
	struct node *tmp=(struct node *) malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=top;
	top=tmp;
}

char pop(){
	struct node *tmp;
	char data=NULL;
	tmp=top;
	top=tmp->link;
	data=tmp->data;
	return data;
}

char Top(){
	return top->data;
}

void display(){
	struct node *ptr=top;
	while(ptr!=NULL){
		printf("%c",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}
