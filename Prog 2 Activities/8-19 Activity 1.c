#include <stdio.h>

/* sum of two numbers using functions */

void sumoftwo(int , int, int*);

int main (){
	
	int num1, num2, sum = 0;
	
	printf("Enter first num: ");
	scanf("%d", &num1);
	printf("Enter second num: ");
	scanf("%d", &num2);
	
	sumoftwo(num1, num2, &sum);
	
	printf("Sum = %d", sum);
	
	return 0;
}

void sumoftwo(int x, int y, int* sum){
	*sum = x + y;
}
