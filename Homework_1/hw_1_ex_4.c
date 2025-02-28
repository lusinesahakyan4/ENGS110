#include <stdio.h>

int main () {

	int input, sum = 0, digit; //Declaring variables

	printf("Enter a number: "); //Getting input from user
	scanf("%d", &input); //Storing the value inside variable "input"

	if (input < 0) { //Making sure the input is a positive number

		input = -input; //If not, making it a positive number
	}

	while (input > 0) { //While the input is a positive number...

		digit = input % 10; //Extracts last digit with modulus
				    //Ex. 159 % 10 == 9

		sum += digit; //Then we add the digit obtained above to "sum" which is initially 0
			      //Ex. sum = 0 + 9 = 9

		input /= 10; //Then we make the input number smaller to get to the second digit 
			     //Ex. 159 /= 10 == 15 
			     //Then the while loop will do the same thing again
			     //Ex. 15 % 10 == 5, sum = 9 + 5 = 14 , input = 15 / 10 = 1 , digit = 1 % 10 = 1, sum = 14 + 1 = 15, input = 1 / 10 = 0 and the loop will stop as the input must be > 0
	}

	printf("\nThe sum of digits is %d\n", sum);

	return 0;
}
