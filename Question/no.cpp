#include <stdio.h>
/*
they defined the function Z. For any positive integer N, Z(N) is the number of zeros at the end of the decimal form of number N!. They noticed that this function never decreases. If we have two numbers N1<N2, then Z(N1) <= Z(N2). It is because we can never "lose" any trailing zero by multiplying by any positive number. We can only get new and new zeros. The function Z is very interesting, so we need a computer program that can determine its value efficiently.

Input

There is a single positive integer T on the first line of input (equal to about 100000). It stands for the number of numbers to follow. Then there are T lines, each containing exactly one positive integer number N, 1 <= N <= 1000000000.

Output

For every number N, output a single line containing the single non-negative integer Z(N).

Algorithm:-

We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. 
So if we count 5s in prime factors, we are done.
 How to count total number of 5s in prime factors of n!? A simple way is to calculate floor(n/5). 
 For example, 7! has one 5, 10! has two 5s. It is done yet, there is one more thing to consider. 
 Numbers like 25, 125, etc have more than one 5. For example if we consider 28!, we get one extra 5 and number of 0s become 6.
  Handling this is simple, first divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s and so on. 
  Following is the summarized formula for counting trailing 0s.

*/
int main(){
	int testcase,no,i;
	scanf("%d",&testcase);
	
	while(testcase--){
		int count=0;
		scanf("%d",&no);
		while(no){
			no/=5;
			count+=no;
		}
		printf("%d\n",count);
	}
return 0;
}
