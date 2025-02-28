#include <stdio.h>

int main(void) 
{
	int N, i; //Declaring integer variables N and i
	int sum = 0; //Declaring integer sum and assigning the value 0 to it

	printf("Enter a number from 1 to 1000: ");
	scanf("%d", &N); //Assigning the entered number to variable N

	if (N < 1 || N > 1000) { //Making sure that the entered number is from 1 to 1000

		printf("\nInvalid input\n");
		
		return 1; //If an invalid number is entered the program will end here
	}

	for (i = 1; i < N; i++) { //If a valid number is entered the for loop will run through all numbers from 1 to N ...
	
		if (i % 3 == 0 || i % 5 == 0) { //... then it will separete the multiples of 3 and 5 ...
			
			sum += i; //... and sum them
		}
	}

	printf("\nHere is the sum of  all natural numbers bellow %d that are multiples of 3 and 5: %d\n", N, sum); //Final output is printed here

	return 0; //the end :)
}
