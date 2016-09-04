#include <stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i;
		scanf("%d",&n);
		int score[n];
		for(i=0;i<n;i++){
			int noc,j=0,sum=0;
			scanf("%d",&noc);
			int type[]={0,0,0,0,0,0};
			for(j=0;j<noc;j++){
				int ctype;
				scanf("%d",&ctype);
				type[--ctype]+=1;
			}
			for(j=0;j<=5;j++){
				if(type[j]>=1)
				sum++;
			}
			switch(sum){
				case 4:
					score[i]=1+noc;
					break;
				case 5:
					score[i]=2+noc;
					break;
				case 6:
					score[i]=4+noc;
					break;
				default:
				      score[i]=noc;
					  break;			
			}
		}
		int bigno=score[0],bigindex=0;
		for(i=1;i<n;i++)
		{
			if(bigno<score[i]){
				bigno=score[i];
				bigindex=i;
			}
			else if(bigno==score[i]){
				if(i==n-1){
					bigindex=-1;
					printf("%s","tie");
					break;
				}
			}
			 
		}
		if(bigindex==0)
		printf("%s","chef");
		else if(bigindex!=-1){
			printf("%d",bigindex+1);
		}
		printf("\n");
	}
	return 0;
}
