#include <stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i;
		scanf("%d",&n);
		int score[n];
		for(i=0;i<n;i++){
			int noc,j=0;
			scanf("%d",&noc);
			score[i]=noc;
			int type[]={0,0,0,0,0,0};
			for(j=0;j<noc;j++){
				int ctype;
				scanf("%d",&ctype);
				type[--ctype]+=1;
			}
			int zeros=0;
			while(zeros<=2){
					zeros=0;
				for(j=0;j<=5;j++){
				if(type[j]==0)
                  zeros++;
				  else
				  type[j]-=1;					
				}
				if(zeros==0)
				score[i]+=4;
				else if(zeros==1)
				score[i]+=2;
				else if(zeros==2)
				score[i]+=1;
			}
	}
		int bigno=score[0],bigindex=0,tiestatus=0;
		for(i=1;i<n;i++)
		{
			if(bigno<score[i]){
				bigno=score[i];
				bigindex=i;
				tiestatus=0;
			}
			else if(bigno==score[i]){
				tiestatus=1;		
				}
					if(i==n-1){
					if(tiestatus){
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
