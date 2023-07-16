#include <stdio.h>

int Factorial(int n)
{
	if (n == 1)
		return 1;
	else 
		return n * Factorial(n - 1);
}	
	
int main(void)
{
	printf("9! : %d\n", Factorial(9));
	return 0;
}