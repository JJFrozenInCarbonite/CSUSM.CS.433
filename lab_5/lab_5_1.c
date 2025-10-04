#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;

    // creates shared memory segment with key 2345, size 1024 bytes, and permissions 0666
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT); 
    printf("Key of shared memory is %d\n", shmid);

    // attach to shared memory
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shared_memory);

    // get input from user
    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100);

    // write data into shared memory
    strcpy(shared_memory, buff);

    // display what was written
    printf("You wrote : %s\n", (char *)shared_memory);

    return 0;
}
