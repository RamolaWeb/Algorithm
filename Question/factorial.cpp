/*You are asked to calculate factorials of some small positive integers.

Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output

For each integer n given at input, display a line with the value of n!



Algorithm to find  Factorial of All Number:-

The trick is to use a variable that will save us, at each moment, the number of digits that is contained in the array. Let's call it m.

Also, since we want only one digit to be stored in every position of array, we need to find a way to "propagate" the carry of larger products to higher digits and sum it afterwards. Let's call the variable to hold the carry, temp.

m -> Variable that contains the number of digits in the array in any given moment;
temp -> Variable to hold the "carry" value resultant of multiplying digits whose product will be larger than 9. (8*9 = 72, we would store 2 on one array position, and 7 would be the "carry" and it would be stored on a different position.)

*/


#include <stdio.h>

int main(){
	int a[1000];
	int no,testcase;
	scanf("%d",&testcase);
	while(testcase--){
	scanf("%d",&no);
	a[0]=1;
	int i,j,temp=0,x,m=1,count=0;
	for(i=1;i<=no;i++){
		
		for(j=0;j<m;j++){
			x=a[j]*i+temp;
			a[j]=x%10;
			temp=x/10;
		}
		while(temp>0){
			a[m]=temp%10;
			temp=temp/10;
			m++;
		}
	}
	for(i=m-1;i>=0;i--)
	printf("%d",a[i]);
	
	printf("\n");
	}

return 0;
}


