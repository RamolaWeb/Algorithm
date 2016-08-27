#include <stdio.h>
int partition(int arr[],int low,int up);
void quicksort(int arr[],int low ,int up);

int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int x[1000],y[1000];
		int num,sum=0;
		scanf("%d",&num);
		for(i=0;i<num;i++)
		scanf("%d",&x[i]);
		for(i=0;i<num;i++)
		scanf("%d",&y[i]);
		quicksort(x,0,num-1);
		quicksort(y,0,num-1);
		
		for(i=0;i<num;i++)
		sum+=x[i]*y[i];
		
		printf("%d",sum);
		printf("\n");
		
		
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
