#include <stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	char num[100000];
	while(t--){
		scanf("%s",num);
		int i=0,noo=0,noz=0;
		while(num[i]!='\0'){
			if(num[i]-48==0)
			noz++;
			else if(num[i]-48==1)
			noo++;
			i++;
		}
		if(noz==1)
		printf("%s","Yes");
		else if(noo==1)
		printf("%s","Yes");
		else
		printf("%s","No");
		printf("\n");
	}
	return 0;
}
