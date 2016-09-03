#include <stdio.h>
#include <string.h>

int main(){
	int t;
	scanf("%d",&t);
	char s[10000];
	while(t--){
		scanf("%s",s);
		int len=strlen(s),i=0,j=0;
		char ans[len];
		while(i<=len/2){
			char s1=s[i],s2=s[len-i-1];
			if(s1=='.'&&s2=='.'){
				ans[i]=ans[len-i-1]='a';
			}
			else if(s1=='.'){
				ans[len-1-i]=ans[i]=s2;
			}
			else if(s2=='.'){
				ans[len-1-i]=ans[i]=s1;
			}
			else if(s1!=s2){
			printf("-1");
			break;
			}
			else{
				ans[i]=ans[len-i-1]=s1;
			}
			
			if(i==len/2){
				while(j<len){
			printf("%c",ans[j]);
			j++;
		}
			}
			i++;
		}
		
		printf("\n");
	}
	return 0;
}
