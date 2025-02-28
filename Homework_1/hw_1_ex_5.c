#include <stdio.h>

int main (void)
{
	int input, digit, output = 0; //Declaring variables

	printf("Enter a number: ");
	scanf("%d", &input); //Storing the input into variable

	while (input != 0) { //While input is not zero 

		digit = input % 10; //Extract the last digit of the number

		output = output * 10 + digit; //Multiply the output by 10 to give "space" for the next digit, or else it will only print the last digit

		input /= 10; //Divide it by 10 to get to the next digit and start the loop again until the modulus is 0, then it will stop
	}

	printf("The inverse is: %d\n", output); //Print the output value

	return 0;
}
