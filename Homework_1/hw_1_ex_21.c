#include <stdio.h>

int main(void)
{
	int n, sum = 0; //Declaring variables

	printf("How many numbers do you want to enter?: "); //First prompt

	if (scanf("%d", &n) != 1) { //Checking for valid input

		printf("Invalid input\n");
		return 0;
	}

	if (n < 1) { //Checking for input greater than one

		printf("Invalid input: negative number or zero\n");
		return 0;
	}
	
	int num[n]; //Declaring array based on users input

	printf("Enter numbers: "); //Second prompt

	for (int i = 0; i < n; i++) { //Assigning values to all elements of the array

		if (scanf("%d", &num[i]) != 1) { //Checking for valid values

			printf("Invalid input number\n");
			return 0;
		}
	}

	for (int i = 0; i < n; i++) { //Summing all elements of the array

		sum += num[i];
	}

	printf("The sum is: %d\n", sum); //Printing sum

	return 0;
}
