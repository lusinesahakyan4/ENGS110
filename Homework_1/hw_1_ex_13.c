#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num, guess, count = 0; //Declaring varibles

	srand(time(NULL)); //Initializing the randomizer using the current timestamp as a seed
	
	num = (rand() % 100) + 1; //Giving variable num a random value from 0 to 100

	printf("Guess what number I have stored: "); //First prompt

	while (1) { //Starting a loop

		if (scanf("%d", &guess) != 1) { //Checking for valid input

                	printf("Invalid input");
                	continue;
        	}

        	if (guess > 100 || guess < 0) { //Checking for valid but incorrect input

                	printf("Invalid input: Not within the range of 0 - 100\n");
        	        continue;
	        }

		if (guess == num) { //If the guess and num values are the same the user "wins"
			
			count++; //Adds one to the count to see how many times you inputted a number
			printf("You guessed it!\n");
			break; //Exits loop
		}

		if (guess > num) { //If the guess is two high continues asking for an input

			count++;
			printf("Your guess is too high, try again: ");
			continue;
		}

		if (guess < num) { //If the guess it too low continues asking for an input

			count++;
			printf("Your guess is too low, try again: ");
			continue;
		}
	}

	printf("Your record: %d\n", count); //Prints the count (how many inputs where given

	return 0;
}
