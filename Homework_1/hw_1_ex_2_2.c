#include <stdio.h>

int main(void)
{
	int a;

	printf("Letter Grade System:\n\n0-59 F \n60-69 D \n70-79 C \n80-89 B \n90-100 A\n"); 

	while(a) { //Creates a loop that will continue asking for a number until an invalid number is entered
		
		printf("\nEnter your grade: ");
		scanf("%d", &a); //Assigns the entered value to variable a
		
		if (a < 0 || a > 100) { //When a number that is not between 0-100 is entered it will print the following and exit the loop

                        printf("\nInvalid grade entered.\n");
                        break;
                }

		if (a >= 0 && a < 60) { //Self explenatory

                	printf("\nYour grade is F\n");
        	}

        	else if (a >= 60 && a < 70) { //Same thing over and over

                	printf("\nYour grade is D\n");
        	}

        	else if (a >= 70 && a < 80) { //and over

                	printf("\nYour grade is C\n");
        	}

        	else if (a >= 80 && a < 90) { //and over

                	printf("\nYour grade is B\n");
        	}

       		 else if (a >= 90 && a <= 100) { //and over

               		 printf("\nYour grade is A\n");
       		}
	}

	return 0; //end of program yaay
}
