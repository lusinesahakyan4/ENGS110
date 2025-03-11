#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define M 500  // Rows in A and C
#define N 500  // Columns in A, Rows in B
#define P 500  // Columns in B and C
#define NUM_THREADS 4

typedef struct {
    int row_start, row_end;
} ThreadData;

int A[M][N], B[N][P], C[M][P];

void *multiply(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    for (int i = data->row_start; i < data->row_end; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    printf("Thread processing rows %d-%d took %lf microseconds\n", data->row_start, data->row_end - 1, time_taken);
    pthread_exit(NULL);
}

void sequential_multiply() {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    printf("Sequential multiplication took %lf microseconds\n", time_taken);
}

int main() {
    srand(42);  // Seed for reproducibility
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = rand() % 10;
        }
    }
    
    printf("Running sequential matrix multiplication...\n");
    sequential_multiply();
    
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int rows_per_thread = M / NUM_THREADS;
    
    printf("Running parallel matrix multiplication with %d threads...\n", NUM_THREADS);
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].row_start = i * rows_per_thread;
        thread_data[i].row_end = (i == NUM_THREADS - 1) ? M : (i + 1) * rows_per_thread;
        pthread_create(&threads[i], NULL, multiply, (void *)&thread_data[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    printf("Parallel multiplication took %lf microseconds\n", time_taken);
    
    return 0;
}

