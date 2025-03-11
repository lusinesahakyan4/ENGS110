#include <stdio.h>
#include <string.h>

void compress_string(char *str) {
    if (str == NULL || *str == '\0') { // Handle null or empty string
        return;
    }
    
    int length = strlen(str);
    char compressed[length * 2]; // Temporary buffer for compressed string
    int index = 0;
    
    for (int i = 0; i < length; i++) {
        char current = str[i];
        int count = 1;
        
        while (i + 1 < length && str[i + 1] == current) { // Count consecutive occurrences
            count++;
            i++;
        }
        
        compressed[index++] = current; // Store character
        index += sprintf(&compressed[index], "%d", count); // Store count as string
    }
    
    compressed[index] = '\0'; // Null-terminate the compressed string
    
    if (strlen(compressed) < length) { // Copy back if compression is beneficial
        strcpy(str, compressed);
    }
}

int main() {
    char str[100]; // Buffer to hold input string
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read input
    
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove newline character if present
    }
    
    compress_string(str); // Compress the string in place
    
    printf("Compressed string: %s\n", str);
    
    return 0;
}
