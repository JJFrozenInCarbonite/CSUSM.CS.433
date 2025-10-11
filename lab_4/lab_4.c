#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *fun1();
void *fun2();

//shared variable
int shared = 1; 

int main() {

    // declare thread variables
    pthread_t thread1, thread2;

    // create thread1
    pthread_create(&thread1, NULL, fun1, NULL);

    // create thread2
    pthread_create(&thread2, NULL, fun2, NULL);

    // wait for thread1 to finish
    pthread_join(thread1, NULL);

    // wait for thread2 to finish
    pthread_join(thread2,NULL);

    //prints the last updated value of shared variable
    printf("Final value of shared is %d\n",shared); 
}

void *fun1() {

    int x;

    //thread one reads value of shared variable
    x = shared;        
    printf("Thread1 reads the value of shared variable as %d\n",x);
    
    //thread one increments its value
    x++;             
    printf("Local update by Thread1: %d\n",x);
    
    //thread one is preempted by thread 2
    sleep(1);        
   
    //thread one updates the value of shared variable
    shared = x;        
    printf("Value of shared variable updated by Thread1 is: %d\n",shared);
}

void *fun2() {
    int y;

    //thread two reads value of shared variable
    y = shared;        
    printf("Thread2 reads the value as %d\n",y);
    
    //thread two increments its value
    y--;             
    printf("Local update by Thread2: %d\n",y);

    //thread two is preempted by thread 1
    sleep(1);        
    
    //thread one updates the value of shared variable
    shared = y;
    printf("Value of shared variable updated by Thread2 is: %d\n",shared);
}
