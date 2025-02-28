#include <stdio.h>

int main(void) 
{
	int n, asc = 1, desc = 1; //Declaring variables and assuming ascending and descending is true

	printf("How many numbers do you want to input?: "); //First prompt

	if (scanf("%d", &n) != 1) { //Checking for valid input

		printf("Invalid input\n");
		return 0;
	}
	
	if (n < 1) { //Checking for positive input

		printf("Invalid input: negative or zero\'n");
	}

	int num[n]; //Declaring integer array with n elements

	printf("Enter %d numbers: ", n); //Second prompt

	for (int i = 0; i < n; i++) { //Assigning values to all elements 

		if (scanf("%d", &num[i]) != 1) { //Checking to valid input

			printf("Invalid input number\n");
			return 0;
		}
	}

	for (int i = 1; i < n; i++) { //Comparing all elements with their previous one, if the previous is smaller than the next descending is false

		if (num[i - 1] < num[i]) {
			
			desc = 0;
			break;
		}
	}

	for (int i = 1; i < n; i++) { //If the previous is larger than the next ascending is false

		if (num[i - 1] > num[i]) {

			asc = 0;
			break;
		}
	}

	if (asc || desc) { //If ascending and descending are still true print yes

		printf("\nYES\n");
	}

	else { //Else print no

		printf("\nno\n");
	}

	return 0;
}
