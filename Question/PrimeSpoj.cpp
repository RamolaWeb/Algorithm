#include <stdio.h>
#include<math.h>
/*
Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Algorithm:-

Following is the algorithm to find all the prime numbers less than or equal to a given integer n by Eratosthenes’ method:

Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
Initially, let p equal 2, the first prime number.
Starting from p, count up in increments of p and mark each of these numbers greater than p itself in the list. These numbers will be 2p, 3p, 4p, etc.; note that some of them may have already been marked.
Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime), and repeat from step 3.


*/
void printallnumber(int,int);
int main(){
	int testcase,n1,n2,i;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d%d",&n1,&n2);
		printallnumber(n2,n1);
		
	}
	return 0;
}

void printallnumber(int finish,int start){
	
	int number[finish],j=0,i=0,k=0,m=0,result[finish-start+1];
	for( i=0;i<finish;i++)
	number[i]=1;
	for( i=0;i<finish-start+1;i++)
	result[i]=1;
	
	
	for( i=2;i<=sqrt(finish);i++){
			if(number[i]){
				for( j=i*i;j<=finish;j+=i){
					number[j]=0;
				}
			}
	}

	
	for(i=2;i<finish;i++)
	{
		if(number[i]){
			m=i;
			// Then we Take each of the prime  number to finish and then first divide the starting number by first number and multiply 
			// by that prime number. After that we remove all element which are equal to that number and increment of prime number till finish.
		    // we need to deselect all prime number  which lie between start and finish.
			if(m<sqrt(finish)){
				j=start/m;
			k=j*m;
			for(;k<=finish;k+=m){
				result[k-start]=0;
			}
			}
			if((m>=start&&m<=finish))
			result[m-start]=1;
			
		}
		
	}
	for( i=0;i<finish-start+1;i++){
		if(result[i]){
			if(start+i!=1)
			printf("%d\n",start+i);
		}
	}
	
	
	
	
	
}
