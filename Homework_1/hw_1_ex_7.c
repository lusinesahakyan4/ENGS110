#include <stdio.h>

int main(void)
{
	int num, digit, reverse = 0; //Declaring variables and initializing reverse

	printf("Enter a number (preferrably a polyndrome hehe): "); //Prompt

	if (scanf("%d", &num) != 1) { //Checking if the input is an integer number

		printf("Input is incorrect\n");
		return 0;
	}
	
	if (num < 0) { //if number is negative make it a positive

		num = -num;
	}
		
	int copy = num; //Create a copy to use for modifications in while and keep num later to compare with reverse

	while (copy > 0) { //While the number is greater than 0
		
		digit = copy % 10; //Extracting the last digit of the number
		reverse = reverse * 10 + digit; //Multiplying reverse with 10 to add "space" and adding the digit
		copy /= 10; //Making the number smaller to get to the next digit
	}

	if (reverse == num) { //If the number and the reverse match then it is a palindrome

		printf("Your number is a palindrome\n");
	}

	else { //If not it is not a palindrome 
		printf("Your number is not a palindrome\n");
	}

	return 0;
}

