#include <stdio.h>

int main() {
	int N, arr[10]; // initializing the array and N

	printf("Please input the elements of the array: ");

	for (int i = 0; i < 10; i++) {

		if (scanf("%d", &arr[i]) != 1) { // obtaining the elements of the array while checking if the data type of input is correct

			printf("\nError: Invalid input\n");
			return 0;
		}
	}

	printf("\nPlease input the number to be removed from the array: ");
	
	if (scanf("%d", &N) != 1) { // obtaining N and checking if it is a number
		
		printf("\nError: Invalid input\n");
		return 0;
	}
	
	for (int i = 0; i < 10; i++) {
		
		if (arr[i] == N) { // case when N is found in the array

			for (int j = i;  j < 9; j++) arr[j] = arr[j + 1]; // shifting value to the left by 1

			arr[9] = 0; // setting the right-most element 0

			printf("\n%d occurs in the array at index %d\n", N, i); // printing the information about the occurence of N
			break;
		}

		if (i == 9) printf("\n%d doesn't occur in the array\nThe array is not modified\n", N); // if i = 9 and the loop is not broken then the N doesn't occur in the array
	}

	printf("\nNew array: ");

	for (int i = 0; i < 10; i++) printf("%d ", arr[i]); // printing the new array

	printf("\n");

	return 0;
}
