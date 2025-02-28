#include <stdio.h>

int main(void)
{
	int height;

	printf("Enter a number: ");
	
	if(scanf("%d", &height) != 1) {

		printf("Invalid input");
		return 0;
	}

	if (height <= 0) {

		printf("Invalid input: negative number or zero");
	}
	
	int row = height - (height / 2);

	for (int i = 1; i <= row; i++) {

		for (int j = row - i; j > 0; j--) {

			printf(" ");
		}

		for (int k = 1; k <= (2 * i - 1); k++) {

			printf("*");
		}

		printf("\n");
	}

	return 0;
}
