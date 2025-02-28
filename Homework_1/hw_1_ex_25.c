#include <stdio.h>

int main(void) 
{
    int N, K, M;

    printf("Please input the size of the array: ");
    
    if (scanf("%d", &N) != 1 || N < 1) {
        
	    printf("\nError: Invalid input. Size must be at least 1.\n");
	    return 0;
    }
    
    int num[N + 1]; // Creating space for one extra element
    
    printf("Please input the elements of the array: ");
    
    for (int i = 0; i < N; i++) {
	    
	    if (scanf("%d", &num[i]) != 1) {
		    printf("\nError: Invalid input.\n");
		    return 0;
	    }
    }
    
    printf("Please input the index to insert the number (0 to %d): ", N);
    
    if (scanf("%d", &M) != 1 || M < 0 || M > N) {
	    
	    printf("\nError: Invalid index. It should be between 0 and %d.\n", N);
	    return 0;
    }
    
    printf("Please input the number to insert: ");
    
    if (scanf("%d", &K) != 1) {
	    
	    printf("\nError: Invalid input.\n");
	    return 0;
    }

    for (int i = N; i > M; i--) {
	    
	    num[i] = num[i - 1];
    }
    
    num[M] = K;

    printf("\nUpdated array: ");
    
    for (int i = 0; i <= N; i++) printf("%d ", num[i]);
    printf("\n");
    
    return 0;
}
