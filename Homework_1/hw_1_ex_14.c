#include <stdio.h>

int main(void) 
{
	int low = 1, high = 100, guess; //Declaring variables
	char answer; 

	printf("Think of a number from 1 - 100 and I'll guess it. \n"); //Intro
	printf("Rules:\nEnter 'y' for yes \nEnter 'h' for too high \nEnter 'l' for too low\n"); //Rule

	while (low <= high) { //Starting a loop

		guess = low + (high - low) / 2; //Using binary search algorithm to find the answer in 7 or less tries

		printf("\nIs your number %d?\n", guess); //First guess is always 50

		if (scanf(" %c", &answer) != 1) { //Scans the answer and checks for valid input

			printf("Invalid input");
			while (getchar() != '\n');
			continue;
		}

		if (answer == 'y') { //If yes it prints the following and exits loop

			printf("I guessed it yaaaaay\n");
			break;
		}

		if (answer == 'h') { //If high it takes the value of guess - 1, assigns it to high, meaning that the available numbers are all numbers bellow 50 
			
			high = guess - 1;
			continue;

		}

		if (answer == 'l') { //If low it takes the value of guess + 1, assigns it to low, meaning that the available numbers are all numbers above 50

			low = guess +1;
			continue;
		}

		else if (answer != 'y' && answer != 'h' && answer != 'l') { //If any other character is entered it will ask for a valid input

			printf("Invalid answer");
			continue;
		}

	} //The loop ends when 'y' is entered (the number is guessed)
	
	return 0;
}

