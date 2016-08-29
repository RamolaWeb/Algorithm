#include <stdio.h>

int main(){
	int table[]={0,0,0,0,1,1,1,1,6,2,4,8, 1,3,9,7,6,4,6,4, 
  5,5,5,5,6,6,6,6, 1,7,9,3,6,8,4,2,1,9,1,9},t;
  scanf("%d",&t);
  while(t--){
  	int a,b,no;
  	scanf("%d %d",&a,&b);
  	if(b==0){
  		no=1;
	  }
	  else if(a==0){
	  	no=0;
	  }
	  else{
	  	no=table[(4*(a%10))+(b%4)];
	  }
  	 
  	printf("%d\n",no);
  }
	return 0;
}
