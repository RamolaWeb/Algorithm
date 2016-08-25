#include <stdio.h>
/*

WE NEED TO FIND ALL SQUARE IN THE N*N GRID.

USE FORMULA n*(n+1)*(2n+1)/6
*/
int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		int square=0;
		square=(n*(n+1)*(2*n+1))/6;
		printf("%d\n",square);
		scanf("%d",&n);
	}
	return 0;
}
