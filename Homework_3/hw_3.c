#include <stdio.h>

enum States {

	START,	//System turns on
	REQUEST_CARD,	//Waits for input
	ACCEPT_CARD,	//Input is valid
	DENY_CARD,	//Input is invalid
	OPEN_GATE,	//Opening gate
	CLOSE_GATE,	//Closing gate
	END	//System turns off or returns to start
};

enum States current_state = START;	//Setting the current state to start, which is the beginning of the fsm

int main () {
	
	int card_number;	//For the users input

	while (current_state != END) {	//Starting a loop, which will end when the state is set to end

		switch (current_state) {
			case START:	//This case prints a welcoming text and proceeds to the next state
				
				printf("Welcome, please proceed with your metro card\n");
				current_state = REQUEST_CARD;
				break;
			
			case REQUEST_CARD:	//Here the program takes an input from the user, i set the rule to be a 4-digit number, to have some limits
				
				printf("Please input the 4 digits of your card ");	//Prompts the user
				
				if (scanf("%d", &card_number) != 1) {	//Checka for valid input and scans it at the same time
					printf("Invalid input\n");
					current_state = DENY_CARD;	//Takes to the end states
					break;
				}

				if (card_number >= 1000 && card_number <=9999) { //Checks for the right number

					current_state = ACCEPT_CARD;	//If it is a 4-digit number, the program proceeds to the next state
				}

				else { current_state = DENY_CARD; }	//If it is not, the input is denied
				break;	

			case ACCEPT_CARD:
				
				printf("\nAccess granted, please proceed");	//The program prints the following to let the user know the state
				current_state = OPEN_GATE;	//Takes to the next state
				break;

			case DENY_CARD:
				
				printf("\nAccess denied, please try again\n");	//In case of an invalid input the gates don't open and the program ends
				current_state = END;
				break;
			
			case OPEN_GATE:		//In case of a valid input the gates open

				printf("\nEnjoy your trip\n");
				current_state = CLOSE_GATE;	//Then it switches to the next state
				break;

			case CLOSE_GATE:

				printf("Closing gate\n");
				current_state = END;	//The program reaches its successfull end
				break;
			}
	}

	return 0;
}
