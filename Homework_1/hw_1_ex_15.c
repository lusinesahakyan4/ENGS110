#include <stdio.h>

int main(void)
{
	int min, max; //Declaring variables
	int num[10]; //Declaring array

	printf("Enter 10 numbers of your choosing: "); //Prompt
	
	for (int i = 0; i < 10; i++) { //Assigning inputs into array

		if (scanf("%d", &num[i]) != 1) { //Checking for invalid inputs

			printf("Invalid input\n");
			return 0;
		}

	}

	min = max = num[0]; //Setting some value to min and max to compare them later
	
	for (int i = 0; i < 10; i++) { //Comparing the value of min and max with each value in the array

		if (num[i] < min) { //If a smaller number is found assign it to min
 
			min = num[i];
		}
		
		if (num[i] > max) { //If a larger number is found assign it to max

			max = num [i];
		}
	}

	printf("\nMinimum: %d \nMaximum: %d\n", min, max); //Output min and max

	return 0;
}

