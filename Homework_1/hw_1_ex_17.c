#include <stdio.h>
#include <math.h>

int main(void) 
{

    	int decimal = 0;
	int neg = 0;
    	char binary[32] = {'0'};
	//Declaring variables and strings

    	printf("Please input a number in binary: (input all 32 bits)\n");
    	scanf("%s", &binary); //Assigning to binary
 
    	for (int i = 0; i < 32; i++) {
        	
		if (binary[i] != '0' && binary[i] != '1') {//If not 0 or 1 will print error
          	
			printf("Invalid input\n");
          		return 0;
        	}
    	}
   
    	if (binary[0] == '1') { 
        	
		neg++; //Indicating the number is negative
        	
		for (int i = 31; i >= 0; i--) { // subtracting 1
            	
			if (binary[i] == '1') { // finding where the first (from the right side) 1 is
                
				binary [i] = '0'; // putting it 0
                
				for (int j = i + 1; j <= 31; j++) { // for all the zeros from that first 1 up to the end putting 1
                    			binary[j] = '1';
                		}
			}

                	break;
            	}

        	for (int i = 0; i < 32; i++) { // complementing the number (1 will become 0, 0 will become 1)
            	
			if (binary[i] == '0') { binary[i] = '1'; }
            		
			else { binary[i] = '0'; }
		}
    	}
   
    	for (int i = 0; i < 32; i++) {
        	
		if (binary[i] == '1') decimal += (1 << (31 - i)); // for each 1 in the binary we add 2 in power of i to the decimal
    	}
   
    	if (neg) decimal = -decimal; // if number was negative we put the minus sign
   
    	printf("\nIts decimal representation is %d", decimal); // printing decimal
    	
	printf("\n");
	
	return 0;
}
