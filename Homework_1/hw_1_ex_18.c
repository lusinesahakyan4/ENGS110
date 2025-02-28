#include <stdio.h>

int main(void) 
{
  	int decimal, binary[32]; // initializing decimal number and array for storing it binary

	printf("Please input a number in decimal system: ");

	if(scanf("%d", &decimal) != 1) { // obtaining decimal while checking if it is a number

		printf("\nError: Invalid input\n");
		return 0;
  	}
  	
	for (int i = 0; i < 32; i++) {
      	
		binary[i] = ((decimal & (1<<i)) ? 1 : 0); /* checking each position of of decimal's binary representation if it is 1, we store 1 in the corresponding index of binary[]*/
  	}
  	
	printf("\nIts binary representation is ");
  	
	for (int i = 31; i >= 0; i--) printf("%d", binary[i]); // printing the binary
	
	printf("\n");
	
	return 0;
}
