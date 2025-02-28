#include <stdio.h>

int main(void) 
{
	int N, M;

        printf("Enter size of list: "); //First prompt

        if (scanf("%d", &N) != 1) { //Checking for valid input

                printf("Invalid input\n");
                return 0;
        }

        if (N < 1) { //Checking for positive input

                printf("Invalid input\n");
        }

        int num[N]; //Declaring array

        printf("Enter %d numbers: ", N); //Second prompt

        for (int i = 0; i < N; i++) { //Assigning values to array elements

                if (scanf("%d", &num[i]) != 1) { //Checking for valid input

                        printf("Invalid number input\n");
                        return 0;
                }
        }

        printf("Please input the index of the element to be deleted: "); //Third prompt
    
	if (scanf("%d", &M) != 1) { // Checking for valid input
	
		printf("\nError: Invalid input\n");
        	return 0;
    	}

	if (M < 0 || M >= N) { // Checking for valid input
	
		printf("\nError: The index of the element should be between 0 and %d\n", N - 1);
	        return 0;
    	}
    
	for (int i = M; i < N - 1; i++) { //Shifting elements to the left
		
		num[i] = num[i + 1];
	}
	
	N--; //Decreasing size of array

	printf("\nUpdated array: ");
	
	for (int i = 0; i < N; i++) {
	    
		printf("%d ", num[i]); // Printing updated array
    }

    printf("\n");

    return 0;
}

