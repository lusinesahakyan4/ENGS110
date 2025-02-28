#include <stdio.h>

int main(void) 
{
	int n; 

	printf("How many numbers do you want to enter?: "); //First prompt

	if (scanf("%d", &n) != 1) { //Checking for valid input

		printf("Invalid input\n");
		return 0;
	}

	if (n < 0) { //Checking for positive input

		printf("Invalid input: Negative number\n");
		return 0;
	}
	
	int num[n]; //Creating array with size of the entered number

	printf("Enter some numbers:\n"); //Second prompt

	for (int i = 0; i < n; i++) { //Adding the entered numbers into the array

		if (scanf(" %d", &num[i]) != 1) { //Checking for valid input

			printf("Invalid input\n");
			return 0;
		}
	}

	for (int i = n - 1; i >= 0; i--) { //Printing the array in reverse order

		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}

		
