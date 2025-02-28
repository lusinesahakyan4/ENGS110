#include <stdio.h>
#include <string.h>

int main(void) 
{
	char num1[100], num2[100]; //Declaring strings
	
	printf("Please input first number: "); //First prompt
	scanf("%s", num1);
        
	printf("Please input second number: "); //Second prompt
        scanf("%s", num2); 
	
	printf("\nThe concatenated number is %s\n", strcat(num1, num2)); //Concatenating and printing
	
	return 0;

}
	
