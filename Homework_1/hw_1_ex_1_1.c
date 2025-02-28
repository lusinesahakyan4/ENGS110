#include <stdio.h>

int main(void) 
{
	float num1, num2;
	char operation;

	printf("What would you like for me to calculate? \nEnter equation: ");
	
	if ((scanf("%f %c %f", &num1, &operation, &num2)) !=3) {

		printf("Invalid input");
		return 0;
	}
	
	if (operation == '+') {

		printf("%.3f %c %.3f = %.3f\n", num1, operation, num2, num1 + num2);
	}

	else if (operation == '-') {

		printf("%.3f %c %.3f = %.3f\n", num1, operation, num2, num1 - num2);
	}

	else if (operation == '*') {

		printf("%.3f %c %.3f = %.3f\n", num1, operation, num2, num1 * num2);
	}

	else if (operation == '/') {
		
		if (num2 != 0) {

			printf("%.3f %c %.3f = %.3f\n", num1, operation, num2, num1 / num2);
		}

		if (num2 == 0) {

			printf("Invalid input: Cannot divide by 0\n");
			return 0;
		}
	}

	return 0;
}

