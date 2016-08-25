#include <stdio.h>
#include <stdlib.h>
struct node *addAtFirst(struct node*,int);
struct node *addAtLast(struct node*,int);
void transversal(struct node *);
struct node *createList(struct node *);
struct node *deletestart(struct node*);
struct node *deleteLast(struct node*);
struct node *insertAfter(struct node *,int,int);
struct node *insertBefore(struct node *,int,int);
struct node *deleteItem(struct node *,int);
int search(struct node *,int);

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
				start=addAtFirst(start,data);
				break;
			case 3:
				printf("Enter The Element To Be added at Last \n");
				scanf("%d",&data);
				start=addAtLast(start,data);
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
				start=deletestart(start);
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

struct node *addAtFirst(struct node *start,int item){
	struct node *tmp=(struct node*) malloc(sizeof(struct node));
	tmp->data=item;
	tmp->link=NULL;
	start=tmp;
	return start;
}

struct node *addAtLast(struct node *start,int item){
	struct node *tmp=(struct node*) malloc(sizeof(struct node)),*ptr=start;
	while(ptr->link!=NULL)
	ptr=ptr->link;
	tmp->data=item;
		ptr->link=tmp;
	tmp->link=NULL;

	return start;
}


void transversal(struct node *start){
	struct node *ptr=start;
	while(ptr!=NULL){
		printf("%d \n",ptr->data);
		ptr=ptr->link;
	}
}

struct node *createList(struct node *start){
	int i,n,data;
	printf("Enter The Number Of List of Created \n");
	scanf("%d",&n);
	if(n==0)
	return start;
	printf("Enter the data to be Enter \n");
	scanf("%d",&data);
	start=addAtFirst(start,data);
	for(i=2;i<=n;i++){
		printf("Enter the data to be Enter \n");
	scanf("%d",&data);
	start=addAtLast(start,data);
	}
	return start;
}

struct node *deletestart(struct node  *start){
	struct node *tmp;
	tmp=start;
	start=tmp->link;
	free(tmp);
	return start;
}
struct node *deleteLast(struct node *start){
	struct node *ptr=start,*tmp;
	
			while(ptr->link->link!=NULL){
		ptr=ptr->link;
	
	
	}
   tmp=ptr->link;
	ptr->link=tmp->link;
	free(tmp);
	return start;
}

struct node *insertAfter(struct node *start,int data,int item){
	struct node *tmp=(struct node *) malloc(sizeof(struct node *)),*ptr=start;
	while(ptr->link!=NULL){
		if(ptr->link->data==item){
			tmp->data=data;
			tmp->link=ptr->link->link;
			ptr->link->link=tmp;
			return start;
			
		}
		ptr=ptr->link;
	}
}

struct node *insertBefore(struct node *start,int data,int item){
	struct node *ptr=start,*tmp=(struct node *) malloc(sizeof(struct node*));
	while(ptr->link!=NULL){
		if(ptr->link->data==item){
			tmp->data=data;
			tmp->link=ptr->link;
			ptr->link=tmp;
			return start;
		}
		ptr=ptr->link;
	}
}

struct node *deleteItem(struct node *start,int data){
	struct node *ptr=start,*tmp;
	while(ptr->link!=NULL){
		if(ptr->link->data==data){
			tmp=ptr->link;
			ptr->link=tmp->link;
			free(tmp);
			return start;
		}
		ptr=ptr->link;
	}
}

int search(struct node *start,int data){
	struct node *ptr=start;
	int count=0;
	while(ptr!=NULL){
		if(ptr->data==data){
			return count;
		}
		count++;
		ptr=ptr->link;
	}
}



