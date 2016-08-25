#include <stdio.h>
#include <stdlib.h>

struct node *addStart(struct node*,int);
struct node *addLast(struct node*,int);
void transversal(struct node *);
struct node *createList(struct node *);
struct node *deleteStart(struct node*);
struct node *deleteLast(struct node*);
struct node *insertAfter(struct node *,int,int);
struct node *insertBefore(struct node *,int,int);
struct node *deleteItem(struct node *,int);
int search(struct node *,int);
struct node *addToEmpty(struct node *,int);

struct node{
	int data;
	struct node *link;
};

int main(){
	struct node *start=NULL;
	int choice,data,item;
	while(1){
		printf("Enter Your Operation Number : \n");
		printf("1. Create The List With Desired Number Of item\n");
		printf("2. Add Element at The Starting\n");
		printf("3. Add Element at The End\n");
		printf("4. Add Element Before any Element\n");
		printf("5. Add Element After any Element\n");
		printf("6. Delete Element at The Starting\n");
		printf("7. Delete Element at The End\n");
		printf("8. Transverse The List \n");
		printf("9. Search The Element \n");
		printf("10. Delete The Particular Item \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				start=createList(start);
				break;
			case 2:
				printf("Enter The Element To Be added at First \n");
				scanf("%d",&data);
				start=addStart(start,data);
				break;
			case 3:
				printf("Enter The Element To Be added at Last \n");
				scanf("%d",&data);
				start=addLast(start,data);
				break;
			case 4:
				printf("Enter The Element To Be added Before Any Item \n");
				scanf("%d",&data);
				printf("Enter The Element Before Which item to be Added \n");
				scanf("%d",&item);
				start=insertBefore(start,data,item);
				break;
			case 5:
				printf("Enter The Element To Be added After Any Item \n");
				scanf("%d",&data);
				printf("Enter The Element After Which item to be Added \n");
				scanf("%d",&item);
				start=insertAfter(start,data,item);
				break;
			case 6:
				start=deleteStart(start);
				break;
			case 7:
				start=deleteLast(start);
				break;
			case 8:
				transversal(start);
				break;
			case 9:
				printf("Enter The Element To be Searched \n");
				scanf("%d",&data);
				search(start,data);
				break;
			case 10:
			    printf("Enter The Element to Delete \n");
				scanf("%d",&data);
				start=deleteItem(start,data);
				break;
			case 11:
			  exit(1);																	
		}
		
	}
	return 0;
}

struct node *addToEmpty(struct node *last,int data){
	struct node *tmp=(struct node *) malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=tmp;
	last=tmp;
	return last;
}

struct node *addStart(struct node *last,int data){
	struct node *tmp=(struct node *) malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=last->link;
	last->link=tmp;
	return last;
}

struct node *addLast(struct node *last,int data){
	struct node *tmp=(struct node *) malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}

struct node *insertAfter(struct node *last,int data,int item){
	struct node *ptr=last->link;
	do{
		 if(ptr->data==item){
			struct node *tmp=(struct node *) malloc(sizeof(struct node));
			tmp->data=data;
			tmp->link=ptr->link;
			ptr->link=tmp;
			if(ptr==last)
			last=tmp;
			return last;
		}
		ptr=ptr->link;
	}while(ptr!=last->link);
}

struct node *insertBefore(struct node *last,int data,int item){
		struct node *tmp=(struct node *) malloc(sizeof(struct node)),*ptr=last;
		do{
			if(ptr->link->data==item){
				tmp->data=data;
				tmp->link=ptr->link;
				ptr->link=tmp;
				return last;
			}
		}while(ptr!=last);
	
}

void transversal(struct node *last){
	struct node *ptr=last;
	do{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}while(ptr!=last);
}

int search(struct node *last,int item){
	struct node *ptr=last->link;
	int count=0;
	while(ptr!=last){
		if(ptr->data==item){
			return count;
		}
		count++;
		ptr=ptr->link;
	}
	return count;
}

struct node *deleteStart(struct node *last){
	struct node *tmp=(struct node *) malloc(sizeof(struct node));
	tmp=last->link;
	last->link=tmp->link;
	free(tmp);
	return last;
}

struct node *deleteLast(struct node *last){
	struct node *tmp=(struct node *) malloc(sizeof(struct node)),*ptr=last->link;
	while(ptr->link!=last){
		ptr=ptr->link;
	}
	tmp=ptr->link;
	ptr->link=tmp->link;
	last=ptr;
	free(tmp);
	return last;
}

struct node *deleteItem(struct node *last,int item){
	struct node *tmp=(struct node *) malloc(sizeof(struct node)),*ptr=last;
	do{
		if(last->data==item){
			last=deleteLast(last);
			return last;
		}
		else if(ptr->link->data==item){
			tmp=ptr->link;
			ptr->link=tmp->link;
			free(tmp);
			return last;
		}
		ptr=ptr->link;
	}while(ptr!=last);
	
}

struct node *createList(struct node *start){
	int i,n,data;
	printf("Enter The Number Of List of Created \n");
	scanf("%d",&n);
	if(n==0)
	return start;
	printf("Enter the data to be Enter \n");
	scanf("%d",&data);
	start=addToEmpty(start,data);
	for(i=2;i<=n;i++){
		printf("Enter the data to be Enter \n");
	scanf("%d",&data);
	start=addLast(start,data);
	}
	return start;
}




