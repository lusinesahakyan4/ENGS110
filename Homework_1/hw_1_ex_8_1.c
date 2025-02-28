#include <stdio.h>

int main(void)
{
	long int num1, num2;

	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	
	if (num1 > 0 && num2 < 0) {

		num1 = -num1;
		num2 = -num2;
	}	

	if (num1 < 0 && num2 < 0) {

		num2 = -num2;
	}

	printf("Here is the concatenated number: %d%d\n", num1, num2);

	return 0;
}

