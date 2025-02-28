#include <stdio.h>

int main(void)
{
	int a; //Variable for grade number

	printf("\nLetter Grade System:\n\n0-59 F \n60-69 D \n70-79 C \n80-89 B \n90-100 A\n");

	printf("\nEnter your grade: "); 
	scanf("%d", &a); //Assigns the entered number to variable a

	if (a >= 0 && a < 60) { //Starts evaluating numbers and printing the corresponding output

		printf("\nYour grade is F\n");
	}
	
	else if (a >= 60 && a < 70) { //Same thing

		printf("\nYour grade is D\n");
	}

	else if (a >= 70 && a < 80) { //again

		printf("\nYour grade is C\n");
	}

	else if (a >= 80 && a < 90) { //again

		printf("\nYour grade is B\n");
	}

	else if (a >= 90 && a <= 100) { //again

		printf("\nYour grade is A\n");
	}

	else { //again

		printf("\nInvalid grade entered.\n");
	}

	return 0; //the end
}
