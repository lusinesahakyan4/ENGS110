#include <stdio.h>

int main (void) 
{
	int N;

	printf("Enter a number: ");
	scanf("%d", &N);
	
	if (N < 0) {

                printf("Error: Not a natural number\n");
        }
	
	if (N == 0 || N == 1) {

		printf("Your number is not a prime\n");
	}

	for (int i = 2; i<= N ; i ++) {

		if (N / i == 1 && N % i == 0) {

			printf("Your number is a prime\n");
			break;
		}

		if (N % i == 0 && N / i != 1) { 
			printf("Your number is not a prime\n");
			break;
		}
	}

	return 0;
}
