#include <stdio.h>
#include <stdlib.h> //For exit_failure and exit_success 

#define FILENAME "hw_2_ex_1.c"  // Name of the current source file

int main() {
    FILE *file = fopen(FILENAME, "r"); //Opens file
    if (file == NULL) { //Checking for errors
        printf("Error opening file"); //Prints the following for the user
        return EXIT_FAILURE; 
    }
    
    int ch; //Storing characters
    int row = 1, col = 0; //As the program will read the file character-by-character these rows and columns will help identify exact locations
    
    printf("Locations of parentheses:\n"); 
    
    while ((ch = fgetc(file)) != EOF) { //Reads until the end of the file
        col++; //For each character in the row col++ will 'count' each characters location on the row
        
        if (ch == '{' || ch == '}') { //Identifying parentheses
            printf("%c found at Row: %d, Column: %d\n", ch, row, col); //Printing output
        }
        
        if (ch == '\n') { //For every new line the row gets + 1 to indicate next row
            row++;
            col = 0; //Column gets set to 0 to allow counting the new rows characters
        }
    }
    
    fclose(file); //When EOF the file closes
    return EXIT_SUCCESS;
}

