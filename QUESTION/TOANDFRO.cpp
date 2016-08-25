#include <stdio.h>
#include <string.h>

int main(){
	int column;
	scanf("%d",&column);
	while(column){
		int i,j,words,count=0,rows;
		char input[300];
		scanf("%s",input);
		words=strlen(input);
		rows=words/column;
		char output[rows][column];
		for(i=0;i<rows;i++){
			if(i%2){
				for(j=column-1;j>=0;j--)
				output[i][j]=input[count++];
				
			}
			else{
				for(j=0;j<column;j++)
				output[i][j]=input[count++];
			}
		}
		
		for(i=0;i<column;i++){
			for(j=0;j<rows;j++){
				printf("%c",output[j][i]);
			}
		}
		
		printf("\n");
		scanf("%d",&column);
	}
	return 0;
}


