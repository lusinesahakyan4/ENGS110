#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024 //Defines the maximum length of a line in the CSV file
#define MAX_COLUMNS 50 //Defines the maximum length the program can handle

void search_csv(const char *filename, int column, const char *search_value) {

	FILE *file = fopen(filename, "r"); //Opens the CSV file for reading 
	if (!file) {

		perror("Error opening file");
		return;
	}

	char line[MAX_LINE]; //Buffer to hold each line read from the file
	char *headers[MAX_COLUMNS]; //Array to store column header 
	int col_count = 0; //Counter to track the number of columns 
	
	//Reads the first line, which contains column headers
	
	if (fgets(line, MAX_LINE, file)) {

		char *token = strtok(line, ",\n"); //Splits the line into tokens based on commas and newlines

		while (token && col_count < MAX_COLUMNS) {

			headers[col_count++] = strdup(token); //Stores each column header
			token = strtok(NULL, ",\n"); //Moves to the next token
		}
	}
	
	// Ensures the user-specified column index is valid

	if (column < 0 || column >= col_count) {

		printf("Invalid column number. Choose between 0 and %d\n", col_count -1);
		fclose(file);
		return;
	}

	printf("Matching rows:\n");

	// Reads and processes each subsequent line of the CSV file
	while (fgets(line, MAX_LINE, file)) {

		char *row[MAX_COLUMNS]; // Array to store individual column values from the current row
		int i = 0;
		char *token = strtok(line, ",\n"); // Splits the row into individual column values

		while (token && i < MAX_COLUMNS) {

			row[i++] = token;
			token = strtok(NULL, ",\n");
		}
		
		// Checks if the value in the specified column matches the search value
		if (i > column && strcmp(row[column], search_value) == 0) {
			
			// Prints the entire row if there is a match
			for (int j = 0; j < i; j++) {

				printf("%s%s", row[j], (j < i - 1) ? ", " : "\n");
			}
		}
	}

	fclose(file); // Closes the file after processing
}

int main () {

	char filename[256]; //Buffer to store the filename
	int column; //Variable to store the column index input by the user
	char search_value[100]; //Buffer to store the search value

	printf("Enter CSV filename: ");
	scanf("%255s", filename);
	
	printf("Enter column number: ");
	scanf("%d", &column);

	printf("Enter search value: ");
	scanf("%99s", search_value);
	
	search_csv(filename, column, search_value); //Calls the function to search the CSV file
	return 0;
}
