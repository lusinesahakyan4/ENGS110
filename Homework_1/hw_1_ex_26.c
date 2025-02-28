#include <stdio.h>
#include <ctype.h>

int main() {
	
	char str[100];
	int choice;
    
    	printf("Please input a string: ");
    
    	if (scanf("%99s", str) != 1) {
	    
		printf("\nError: Invalid input.\n");
	    	return 0;
    	}
    
    	printf("Enter 1 for uppercase, 2 for lowercase: ");
    
    	if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {

		printf("\nError: Invalid choice.\n");
	    	return 0;
    	}
    
    	for (int i = 0; str[i] != '\0'; i++) {
	    
		if (choice == 1) {
		
			str[i] = toupper(str[i]);
	    	}
	    
	    	else {
			str[i] = tolower(str[i]);
	    	}
    	}    
    
    	printf("\nConverted string: %s\n", str);
    
    	return 0;
}
