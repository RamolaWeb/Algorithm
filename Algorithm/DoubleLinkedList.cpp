#include <stdio.h>
#include <stdlib.h>
struct node *addAtStart(struct node*,int);
struct node *addAtlast(struct node*,int);
void transversal(struct node *);
struct node *createList(struct node *);
struct node *deleteStart(struct node*);
struct node *deleteLast(struct node*);
struct node *insertAfter(struct node *,int,int);
struct node *insertBefore(struct node *,int,int);
struct node *deleteItem(struct node *,int);
int search(struct node *,int);
struct node *addAtEmpty(struct node *,int);

struct node{
	int data;
	struct node *prev;
	struct node *next;
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
				start=addAtStart(start,data);
				break;
			case 3:
				printf("Enter The Element To Be added at Last \n");
				scanf("%d",&data);
				start=addAtlast(start,data);
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

struct node *addAtEmpty(struct node *start,int data){
	struct node *tmp=(struct node*) malloc(sizeof(struct node));
	tmp->data=data;
	tmp->next=NULL;
	tmp->prev=NULL;
	start=tmp;
	return start;
}

struct node *addAtStart(struct node *start,int data){
	struct node *tmp=(struct node*) malloc(sizeof(struct node));
	tmp->data=data;
	tmp->next=start;
	tmp->prev=NULL;
	if(start->prev!=NULL)
	start->prev=tmp;
	start=tmp;
	return start;
}

struct node *addAtlast(struct node *start,int data){
	struct node *ptr=start,*tmp=(struct node *) malloc(sizeof(struct node));
	while(ptr->next!=NULL)
	 ptr=ptr->next;
	tmp->data=data;
	tmp->next=NULL;
	tmp->prev=ptr;
	ptr->next=tmp;
	return start;
}

struct node *insertAfter(struct node *start,int data,int item){
	struct node *ptr=start,*tmp=(struct node *) malloc(sizeof(struct node));
	while(ptr->next!=NULL){
		if(ptr->data==item){
			tmp->data=data;
			tmp->next=ptr->next;
			tmp->prev=ptr;
			ptr->next->prev=tmp;
			ptr->next=tmp;
			return start;
		}
		ptr=ptr->next;
	}
}

struct node *insertBefore(struct node *start,int data,int item){
	struct node *ptr=start,*tmp=(struct node *) malloc(sizeof(struct node));
	while(ptr->next!=NULL){
		if(ptr->data==item){
			tmp->data=data;
			tmp->next=ptr;
			tmp->prev=ptr->prev;
			ptr->prev->next=tmp;
			ptr->prev=tmp;
			return start;
		}
		ptr=ptr->next;
	}
}

void transversal(struct node *start){
	struct node *ptr=start;
	while(ptr!=NULL){
		printf("%d \n",ptr->data);
		ptr=ptr->next;
	}
}

int search(struct node *start,int item){
		struct node *ptr=start;
		int count=0;
	while(ptr!=NULL){
		if(ptr->data==item){
			return count++;
		}
		count++;
		ptr=ptr->next;
	}
}

struct node *deleteStart(struct node *start){
	struct node *tmp;
	tmp=start;
	
	if(start->next!=NULL){
		start->next->prev=NULL;
	start=start->next;
	}
	
	free(tmp);
	return start;
}

struct node *deleteLast(struct node *start){
	struct node *tmp,*ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	tmp=ptr;
	ptr->prev->next=NULL;
	free(tmp);
	return start;
}

struct node *deleteItem(struct node *start,int item){
	struct node *tmp,*ptr=start;
	while(ptr->next!=NULL){
		if(ptr->data==item){
			tmp=ptr;
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(tmp);
			return start;
		}
		ptr=ptr->next;
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
	start=addAtEmpty(start,data);
	for(i=2;i<=n;i++){
		printf("Enter the data to be Enter \n");
	scanf("%d",&data);
	start=addAtlast(start,data);
	}
	return start;
}



