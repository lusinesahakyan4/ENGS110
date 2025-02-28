#include <stdio.h>

int main(void)
{
	int n;
	char order;

	printf("Enter size of list: ");

	if (scanf("%d", &n) != 1) {

		printf("Invalid input\n");
		return 0;
	}

	if (n < 1) {

		printf("Invalid input\n");
	}

	int num[n];

	printf("Enter %d numbers: ", n);

	for (int i = 0; i < n; i++) {

		if (scanf("%d", &num[i]) != 1) {

			printf("Invalid number input\n");
			return 0;
		}
	}
	
	while (getchar() != '\n');

	printf("Print in ascending (a) or descending (d) order?: ");

	scanf("%c", &order);

	if(order != 'a' && order != 'd') {

		printf("Invalid character input");
		while(getchar() != '\n');
		return 0;
	}

	for (int i = 0; i < n; i++) {

		int swap = 0;

		for (int j = 0; j < (n - i - 1); j++) {

			if ((order == 'a' && num[j] > num[j + 1]) || (order == 'd' && num[j] < num[j + 1])) { 

				num[j] = num[j] ^ num[j+1];
				num[j + 1] = num[j] ^ num[j+1];
				num[j] = num[j] ^ num[j+1];
				swap = 1;
			}
		}

		if (swap == 0) {

			break;
		}
	}

	for (int i = 0; i < n; i++) {

		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}

