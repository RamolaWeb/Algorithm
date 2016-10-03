#include <stdio.h>
#include <string.h>

void swap(char *x,char *y){
	char temp=*x;
	*x=*y;
	*y=temp;
}

void permute(char *a,int start,int end){
	int i;
	if(start==end)
	{
		printf("%s\t",a);
	}
	else{
		for( i=start;i<=end;i++){
			swap((a+start),(a+i));
			permute(a,start+1,end);
			swap((a+start),(a+i));
		}
		
	}
}

int main(){
	char word[1000];
	scanf("%s",word);
	permute(word,0,strlen(word)-1);
}
