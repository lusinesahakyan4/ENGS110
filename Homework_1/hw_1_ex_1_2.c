#include <stdio.h>

int main(void) 
{
	int num1, num2;
	char operation;

	printf("What would you like for me to calculate? \nEnter equation: ");
	
	if ((scanf("%d %c %d", &num1, &operation, &num2)) !=3) {

		printf("Invalid input");
		return 0;
	}
	
	switch (operation) {

		case '+':

			printf("%d %c %d = %d\n", num1, operation, num2, num1 + num2);
			break;
	
		case '-':

			printf("%d %c %d = %d\n", num1, operation, num2, num1 - num2);
			break;

		case '*':

			printf("%d %c %d = %d\n", num1, operation, num2, num1 * num2);
			break;

		case '/':
			
			if (num2 == 0) {

				printf("Invalid input: Cannot divide by 0\n");
				break;
			}
			
			
			else {
				printf("%d %c %d = %d\n", num1, operation, num2, num1 / num2);
			}

			break;
		
		default:

			printf("Invalid input: Cannot calculate");
	}

	return 0;
}

