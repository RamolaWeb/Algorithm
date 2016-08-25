#include <stdio.h>
#define MAX 5000
int partition(int arr[],int low,int up);
void quicksort(int arr[],int low ,int up);
int main(){
	int arr[MAX],testCase,n,i=0,j=0,diff,k=0;
	scanf("%d",&testCase);
	for(i=0;i<testCase;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
			quicksort(arr,0,n-1);
	
	diff=arr[1]-arr[0];
	for(k=2;k<n;k++){
		 int newdiff=arr[k]-arr[k-1];
		if(newdiff<diff)
		   diff=newdiff;
	}
	printf("%d\n",diff);
	}
	

	return 0;
}

void quicksort(int arr[],int low, int up){
	int pivloc;
	if(low>=up)
	  return;
	  pivloc=partition(arr,low,up);
	  quicksort(arr,low,pivloc-1);
	  quicksort(arr,pivloc+1,up);	
}

int partition(int arr[],int low,int up){
	int temp,i,j,pivot;
	i=low+1;
	j=up;
	pivot=arr[low];
	while(i<=j){
		while((arr[i]<pivot)&&(i<up))
		i++;
		while(arr[j]>pivot)
		j--;
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
		else{
			i++;
		}
		
	}
	
	arr[low]=arr[j];
	arr[j]=pivot;
	return j;
}
