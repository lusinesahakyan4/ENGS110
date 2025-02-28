#include <stdio.h>

int main(void) 
{
	int height; //Declaring variable

	printf("Enter a number: "); //Prompt

	if (scanf("%d", &height) != 1) { //Checking for valid input

		printf("Invalid input");

		return 0;
	}
	
	if (height <= 0) { //Checking for positive number

		printf("Invalid input: negative number or zero");
		return 0;
	}

	for (int i = 1; i <= height; i++) { //First triangle: The first for will do as many loops as the user inputs
					
		for (int j = 1; j <= i; j++) { //For every loop it will print a * equal to the number of the loop, for example in loop one it will print one *

			printf("*");
		}

		printf("\n"); //A newline is printed after each loop
	}
	
	for (int a = 1; a <= height; a++) { //Second triangle: To print an "indented" triangle spaces need to be printed. The first for will do as many loops as inputted

		for (int b = 1; b <= height - a; b++) { //First the spaces will be printed, for example in loop one input - one spaces will print, loop two input - two ect.

			printf(" ");
		}

		for (int c = 1; c <= a; c++) { //Immediately after the loop a * will be printed according to the loop number, for example loop one *, loop two ** ect

			printf("*");
		}

		printf("\n"); //After each loop a newline will be printed
	}

	return 0;
}
