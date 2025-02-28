#include <stdio.h>

int main(void) 
{
	int length, width; //Declaring variables

	printf("Input length and width: "); //Prompt

	if (scanf("%d %d", &length, &width) != 2) { //Checking for integer

		printf("Incorrect input\n");
		return 0;
	}

	if (width < 0 || length < 0) {

		printf("Invalid input: Negative number\n");
		return 0;
	}

	for (int i = 0; i < length; i++) { //Printing the "top" of the box
			
		printf("*");
	}

	printf("\n"); //Printing newline for the "body" of the box
		
	for (int j = 0; j < width - 2; j++) { //Body of the box (width - 2 because the top and bottom count as widths) 

		printf("*"); 
		
		for (int i = 0; i < length - 2; i++) { //Leaving the "inside" empty (there are spaces printed of length - 2 as the first and last characters of width count as length)

			printf(" ");
		}

		if (length > 1 && width > 1) { //If the result of width - 2 is greater than 1 it will start printing another row for width

			printf("*");
		}

		printf("\n"); //This newline takes to the next row
	}

	if (width > 1) { //The bottom will print for boxes with width greater than 1

		for (int i = 0; i < length; i++) { //The "bottom" of the box

			printf("*");
		}
	}

	printf("\n"); //For visual aesthetics

	return 0;
}
