#include <stdio.h>

int main(void)
{
	int N, i, j, count;

	printf("Enter a natural number: ");
	scanf("%d", &N);
	printf("\n");

	if (N < 0) {

	        printf("Error: Not a natural number\n");
	}
	
	if (N == (0 || 1 || 2)) {

		printf("There are no prime numbers before %d\n", N);
		return 0;
	}

	for (i = 2; i < N; i++) {

		count = 0;

		for (j = 2; j <= i / 2; j++) {

			if (i % j == 0) {

				count ++;
				break;
			}
		}

		if (count == 0) {

			printf("%d\t", i);
		}
	}	
	
	printf("\nAbove are all the prime numbers before %d", N);
        printf("\n");

	return 0;
}
	
