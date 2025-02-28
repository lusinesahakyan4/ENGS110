#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare (const void *a, const void *b) {

    return (*(char *)a - *(char *)b); //qsort function rules
}

int main(void) 
{
	char str1[100], str2[100]; // initializing strings

	printf("Please input first string: ");
	scanf("%s", str1); // obtaining str1

	printf("\nPlease input second string: ");
        scanf("%s", str2); // obtaining str2

	if (strlen(str1) != strlen(str2)) { //If they have different lenghts they are not anagrams
		
		printf("\nStrings are not anagrams\n");
		return 0;
	}

	qsort(str1, strlen(str1), sizeof(char), compare); // sorting str1 to compare later
        qsort(str2, strlen(str2), sizeof(char), compare); // sorting str2 to compare letter
	
	if (!strcmp(str1, str2)) printf("\nStrings are anagrams\n"); //If sorted versions are the same they are anagrams
	else printf("\nStrings are not anagrams\n");

	return 0;
}
