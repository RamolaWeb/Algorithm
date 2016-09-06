#include <stdio.h>
int smallestPrimeDivisior(int);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int num,query,i=0;
		scanf("%d %d",&num,&query);
		int numarray[num];
		for(i=0;i<num;i++)
			scanf("%d",&numarray[i]);
		for(i=0;i<query;i++){
			int q,l,r,large=1;
			scanf("%d %d %d",&q,&l,&r);
			l-=1;
			switch(q){
				case 0:
					while(l<r){
						numarray[l]=numarray[l]/smallestPrimeDivisior(numarray[l]);
						l++;
					}
					break;
				case 1:
					while(l<r){
						int b=numarray[l];
						int a=smallestPrimeDivisior(b);
					   if(a>large)
					   large=a;
					   l++;
					}
					printf("%d ",large);
				break;	
			}
		}	
		printf("\n");
	}
	return 0;
}


int smallestPrimeDivisior(int target){
	int i=0;
	if(target%2==0)
	return 2;
	for(i=3;i*i<=target;i+=2){
		if(target%i==0){
			return i;
		}
		
	}
	if(target>2)
	return target;
	return 1;
}

