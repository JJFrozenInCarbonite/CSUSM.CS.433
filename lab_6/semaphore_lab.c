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


    sem_init(&s, 0, 1);  // initialize semaphore variables 1
    // 1st argument is address of variable
    // 2nd is number of processes sharing semaphore
    // 3rd is the inital value of semaphore

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared); // prints the last updated value of shared variable

    sem_destroy(&s);
    return 0;
}

void *fun1(void *arg) {
    int x;

    sem_wait(&s); // executes wait operation on s

    x = shared;   // thread1 reads value of shared variable
    printf("Thread1 reads the value as %d\n", x);

    x++;          // thread1 increments its value
    printf("Local updation by Thread1: %d\n", x);

    sleep(1);     // thread1 is preempted by thread2

    shared = x;   // thread1 updates the value of the shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);

    sem_post(&s); 
}

void *fun2(void *arg) {
    int y;

    sem_wait(&s); 

    y = shared;   // thread2 reads value of shared variable
    printf("Thread2 reads the value as %d\n", y);

    y--;          // thread2 decrements its value
    printf("Local updation by Thread2: %d\n", y);

    sleep(1);     // thread2 is preempted by thread1

    shared = y;   // thread2 updates the value of shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);

    sem_post(&s); // leave critical section
}