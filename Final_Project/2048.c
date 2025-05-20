#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 4 // Size of the grid 4x4
#define TARGET 2048 // Target tile value

int grid[SIZE][SIZE]; // Game board

// Function to display the welcome screem
void WelcomeScreen() {
    	printf("=====================================\n");
    	printf("            Welcome to 2048!         \n");
    	printf("=====================================\n");
    	printf("                By                   \n");
    	printf("        Samvel Aghakhanyan          \n");
    	printf("                and                 \n");
    	printf("           Lusine Sahakyan          \n");
    	printf("=====================================\n");
    	printf("      Use W A S D to move tiles      \n");
    	printf("         Press Enter to start        \n");
	printf("       Press Q to quit anytime       \n");
    	printf("=====================================\n");
    	getchar(); // Waits until user presses ENTER
}

// Function to initialize grid and add 2 starting tiles
void InitGrid(int grid[SIZE][SIZE]) {
    	for (int i = 0; i < SIZE; i++) { // Setting all tiles to zero
        	for (int j = 0; j < SIZE; j++) {
            		grid[i][j] = 0;
		}
	}

    	for (int i = 0; i < 2; ++i) { // Setting values of two random tiles to 2
        	int x = rand() % SIZE;
        	int y = rand() % SIZE;
        	while (grid[x][y] != 0) {
            		x = rand() % SIZE;
            		y = rand() % SIZE;
        	}
        	grid[x][y] = 2;
    	}
}

// Function for printing grid
void PrintGrid(int grid[SIZE][SIZE]) {
    	printf("=====================================\n");
    	printf("                2048                 \n");
    	printf("=====================================\n");

    	for (int i = 0; i < SIZE; i++) {
        	printf("    |"); // Left padding
        	for (int j = 0; j < SIZE; j++) {
            		if (grid[i][j] == 0) printf("      |"); // if value of tile is 0, print space
			else printf(" %4d |", grid[i][j]); // if value of tile is above 0, print number
        	}
        	printf("\n");
        	printf("-------------------------------------\n"); // Bottom line for row
    	}
}

// Function to add random 2 to tiles
void RandomTile(int grid[SIZE][SIZE]) {
    	int empty[SIZE * SIZE][2]; // To store coordinates of empty tiles
    	int count = 0;

    	for (int i = 0; i < SIZE; i++) {
        	for (int j = 0; j < SIZE; j++) {
            		if (grid[i][j] == 0) {
				empty[count][0] = i;
				empty[count][1] = j;
				count++;
			}
		}
	}

    	if (count > 0) { // If there are empty tiles, randomly spawn on one of them 2
        	int r = rand() % count;
        	int x = empty[r][0];
        	int y = empty[r][1];
        	grid[x][y] = 2;
    	}
}

// Function to check if moves are possible
bool CanMove(int grid[SIZE][SIZE]) {
    	for (int i = 0; i < SIZE; i++) {
        	for (int j = 0; j < SIZE; j++) {
            		if (grid[i][j] == 0) return true; // empty tile
            		if (j < SIZE - 1 && grid[i][j] == grid[i][j + 1]) return true; // Can merge left/right
            		if (i < SIZE - 1 && grid[i][j] == grid[i + 1][j]) return true; // Can merge up/down
        	}
	}
   	return false;
}

// Function to check if player has won
bool CheckWin(int grid[SIZE][SIZE]) {
    	for (int i = 0; i < SIZE; i++) {
        	for (int j = 0; j < SIZE; j++) {
            		if (grid[i][j] == TARGET) return true; // if any tile's value is 2048, player won
		}
	}
    	return false;
}

// Function to slide and merge all rows left, used for any direction, after rotation
bool SlideLeft(int grid[SIZE][SIZE]) {
    	bool moved = false;
    	for (int i = 0; i < SIZE; i++) {
        	int temp[SIZE] = {0};
        	int idx = 0;

        	// Slide non-zero elements to front
        	for (int j = 0; j < SIZE; j++) {
            		if (grid[i][j] != 0) temp[idx++] = grid[i][j];
        	}

        	// Merge adjacent tiles with same values
        	for (int j = 0; j < SIZE - 1; j++) {
            		if (temp[j] != 0 && temp[j] == temp[j + 1]) {
                		temp[j] *= 2;
                		temp[j + 1] = 0;
                		moved = true;
            		}
        	}

        	// Slide again after merge
        	int final[SIZE] = {0};
        	idx = 0;
        	for (int j = 0; j < SIZE; j++) {
            		if (temp[j] != 0) final[idx++] = temp[j];
        	}

        	// Update grid (copy final row back and check if move happened
        	for (int j = 0; j < SIZE; j++) {
            		if (grid[i][j] != final[j]) {
                		moved = true;
                		grid[i][j] = final[j];
            		}
        	}
    	}
    	return moved;
}

// Function to rotate grid 90 degrees clockwise
void RotateGrid(int grid[SIZE][SIZE]) {
    	int tmp[SIZE][SIZE];
    	
	for (int i = 0; i < SIZE; i++) {
        	for (int j = 0; j < SIZE; j++) {
            		tmp[j][SIZE - 1 - i] = grid[i][j];
		}
	}

    	for (int i = 0; i < SIZE; i++) {
        	for (int j = 0; j < SIZE; j++) {
            		grid[i][j] = tmp[i][j];
		}
	}
}

// Function to move in direction using rotation
bool Move(char dir, int grid[SIZE][SIZE]) {
    	bool moved = false;
    	int rot = 0;

    	switch (dir) { // Based on pressed letter, function determines how many rotations are needed
        	case 'w': rot = 3; break; // 270 degree
        	case 'd': rot = 2; break; // 180 degree
        	case 's': rot = 1; break; // 90 degree
        	case 'a': rot = 0; break; // 0 degree (no rotation)
        	default: return false; // Invalid input
    	}

    	for (int i = 0; i < rot; i++) RotateGrid(grid); // Rotating
    	moved = SlideLeft(grid); // Moving
    	for (int i = 0; i < (4 - rot) % 4; i++) RotateGrid(grid); // Rotating back

    	return moved;
}

// Function to ask user if they want to play again
bool PlayAgain() {
    	char c;
    	printf("\nDo you want to play again? (y/n): ");
    	scanf(" %c", &c);
    	return (c == 'y' || c == 'Y');
}

// Main game loop
int main() {
    	srand(time(NULL));
    	char input;
    	bool playing = true;

    	while (playing) { // Loop runs while game is running
        	WelcomeScreen(); // Prints welcome screen
        	InitGrid(grid); // Initializing the grid

        	while (true) {
            		PrintGrid(grid); // Printing the grid

            		if (CheckWin(grid)) { // Checking if player won
                		printf("\nCongratulations! You reached 2048!\n");
                		break;
            		}

            		if (!CanMove(grid)) { // Checking if player can move, if no - game over
                		printf("\nGame Over! No more moves.\n");
                		break;
            		}

            		printf("Enter move (W/A/S/D): "); // Asking for input
            		scanf(" %c", &input);
            		input = tolower(input);

			if (input == 'q') { // Exiting game if Q is pressed
                		printf("\nExiting the game. Goodbye!\n");
                		exit(0);
            		}

            		if (input != 'w' && input != 'a' && input != 's' && input != 'd') { // If moving letters are pressed, moves accordingly
                		printf("\nInvalid input! Please use W, A, S, or D.\n");
                		continue;
            		}

            		if (Move(input, grid)) RandomTile(grid); // Generating random tile on each move
            		else printf("\nNo movement possible in that direction!\n"); // Warning if no move is possible
        	
		}

        	if (!PlayAgain()) playing = false; // Checking if player wants to play again
    	}

    	printf("Thanks for playing!\n");
    	return 0;
}

