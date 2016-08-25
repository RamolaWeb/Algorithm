#include <stdio.h>

/*

Input

The input consists of N cases (equal to about 10000). The first line of the input contains only positive integer N. Then follow the cases. Each case consists of exactly one line with two positive integers separated by space. These are the reversed numbers you are to add.

Output

For each case, print exactly one line containing only one integer - the reversed sum of two reversed numbers. Omit any leading zeros in the output.

Algorithm:-

Input:  num
(1) Initialize rev_num = 0
(2) Loop while num > 0
     (a) Multiply rev_num by 10 and add remainder of num  
          divide by 10 to rev_num
               rev_num = rev_num*10 + num%10;
     (b) Divide num by 10
(3) Return rev_num
*/


int reversenumber(int);
int main(){
	int number1,number2,testcase;
	scanf("%d",&testcase);
	while(testcase--){
	scanf("%d %d",&number1,&number2);
	printf("%d\n",reversenumber(reversenumber(number1)+reversenumber(number2)));	
	}
	return 0;
}

int reversenumber(int number){
	int r_number=0,num=number;
	while(num!=0){
		r_number=r_number*10+num%10;
		num=num/10;
	}
	return r_number;
}
