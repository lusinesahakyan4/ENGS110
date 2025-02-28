#include <stdio.h>

int main(void) 
{
	int num;

	printf("Enter a number: "); //Prompt

	if (scanf("%d", &num) != 1) { //Checking if the number is an integer (as the scanf hasn't stored the value yet this part of the program checks if the input is 1 (true) or not 1 (0/false) 

		printf("Input is not an integer\n");

		return 0;
	} 

	if (num < 2) { //Numbers less than 2 cannot be powers of 2

		printf("Your number is not a power of 2");

		return 0;
	}

	if ((num & (num - 1)) == 0) { //Using bitwise operations I check if its a power of 2 as all binary numbers representing powers of two can be written with only one 1 and the rest are 0, therefore the 
				     //& operation will always be equal to 0 for powers of 2

		printf("Your number is a power of 2\n");
	}
		
	else { //If the & does not produce 0 it prints the following
		printf("Your number is not a power of 2\n");
	}

	return 0;
}
