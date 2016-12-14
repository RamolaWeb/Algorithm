#include <stdio.h>

int sum(int);
void divisiblebyEleven(int);
int properDivisor(int );
int main(){
	int m,s;
	scanf("%d",&m);
	sum(m);
	divisiblebyEleven(m);
	printf("The sum is %d \n",properDivisor(m));
	return 0;
}

int sum(int n){
	int s=0;
	if(n/10==0)
	return n;
	s+=n%10+sum(n/10);
	if(!(s%9))
	printf("%s\n","Divisible By 9");
}

void divisiblebyEleven(int num){
	int s1=0,s2=0,diff=0;
	if(num==0)
	{
		printf("%s\n","Divisible By 11");
		return ;
	}
	
	else if(num<10)
	{
			printf("%s\n","Not Divisible By 11");
		return ;
	}
	
	while(num>0){
		s1+=num%10;
		num=num/10;
		s2+=num%10;
		num=num/10;
	}
	diff=s1>s2?(s1-s2):(s2-s1);
	divisiblebyEleven(diff);
}

int properDivisor(int n){
	int sum=0;
for(int i=1;i<n;i++){
		if(n%i==0){
			printf("%d\n",i);
			sum+=i;
		}
	}
	return sum;
}


