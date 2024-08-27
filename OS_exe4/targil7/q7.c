#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 20

long accum = 0;
pthread_mutex_t lock;

void *square(void *param) {
    int x = *(int *)param;
    pthread_mutex_lock(&lock);
    accum += x * x;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int *params[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    for (long t = 0; t < NUM_THREADS; t++) {
        params[t] = malloc(sizeof(int));
        *params[t] = t + 1;
        pthread_create(&threads[t], NULL, square, (void *)params[t]);
    }

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
        free(params[t]);
    }

    printf("%ld\n", accum);

    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}
