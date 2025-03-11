#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    if (str == NULL || *str == '\0') { // Handle null or empty string
        return;
    }
    
    char *start = str; // Pointer to the beginning of the string
    char *end = str + strlen(str) - 1; // Pointer to the last character
    
    while (start < end) { // Swap characters until pointers meet
        char temp = *start;
        *start = *end;
        *end = temp;
        start++; // Move start forward
        end--;   // Move end backward
    }
}

int main() {
    char str[100]; // Buffer to hold input string
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read string from input
    
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove newline character if present
    }
    
    reverse_string(str); // Reverse the string in place
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}

