// semaphore_lab.c
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

void *fun1(void *arg);
void *fun2(void *arg);

int shared = 1;     // shared variable
sem_t s;            // semaphore variable

int main(void) {
    // sem_init(&s, pshared, value)
    // pshared = 0 means threads in the same process
    // value   = 1 means one permit available
    sem_init(&s, 0, 1);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared);

    sem_destroy(&s);
    return 0;
}

void *fun1(void *arg) {
    int x;

    sem_wait(&s); // enter critical section

    x = shared;   // read
    printf("Thread1 reads the value as %d\n", x);

    x++;          // increment
    printf("Local updation by Thread1: %d\n", x);

    sleep(1);     // simulate a context switch while still holding the semaphore

    shared = x;   // write back
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);

    sem_post(&s); // leave critical section
    return NULL;
}

void *fun2(void *arg) {
    int y;

    sem_wait(&s); // enter critical section

    y = shared;   // read
    printf("Thread2 reads the value as %d\n", y);

    y--;          // decrement
    printf("Local updation by Thread2: %d\n", y);

    sleep(1);     // simulate a context switch while still holding the semaphore

    shared = y;   // write back
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);

    sem_post(&s); // leave critical section
    return NULL;
}
