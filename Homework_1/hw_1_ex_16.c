#include <stdio.h>

int main(void) 
{
	int num, occ[10] = {0}; //Declaring variable and array

	printf("Enter as many numbers as you'd like from range 1 - 10 \nEnter -1 to finish the list\n"); //Prompt
	
	while (1) { //Starting loop for inputting numbers

		if (scanf(" %d", &num) != 1) { //Checking for valid input

			printf("Invalid input\n");
			while (getchar() != '\n');
			continue;
		}

                if (num == -1) { //Checking for -1 to finish list
		       	
			break;
		}

		if (num < 1 || num > 10) { //Checking for invalid inputs

			printf("Not within the range\n");
			continue;
		}

		occ[num - 1]++; //Since 1 in the array is the 0th number each "number - 1"-th will be increased by one 
	}

	for (int i = 0; i < 10; i++) { //Printing occurances

		printf("Occurence of %d: %d\n", i + 1, occ[i]);
	}

	return 0;
}
