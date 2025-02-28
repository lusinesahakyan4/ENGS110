#include <stdio.h>
#include <string.h>

int main() {
	char str1[100], str2[100]; // initializing both strings
	
	printf("Please input the first string: ");
	scanf("%s", str1); // obtaining str1
        
	printf("\nPlease input the second string: ");
        scanf("%s", str2); // obtaining str2
			   
	char *p = strstr(str1, str2); // using strstr() to find the occurrence of str2 in str1
	
	if (p != NULL) {

		printf("\n%s is a substring of %s\nIts first occurrence is here: %s\n", str2, str1, p); // if p is not NULL, str2 is a substring of str1, we print it
	}
	
	else {

		printf("\n%s is not a substring of %s\n", str2, str1); // else, str2 doesn't occur in str1
	}	
	
	return 0;
}
