server.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/types.h>
#include <semaphore.h>

    void
    main()
{
    //server reads the shared memory

    //creating the semaphore

    sem_t *x2;
    sem_t *x1;
    x1 = sem_open("sSem4", O_CREAT, 0666, 0);
    x2 = sem_open("cSem4", O_CREAT, 0666, 1);
    //reading shared memory
    key_t key = ftok("sharedmem", 65);
    int i = 0;
    //shared memory id
    int shmid = shmget(key, 2 * sizeof(char), IPC_CREAT | 0666);
    //attach to the segment
    char *str = (char *)shmat(shmid, NULL, 0);
    while (i < 5)
    {
        sem_wait(x1);
        //unique key generate
        //sever data read

        printf("Data read from memory: %s\n", str);

        //detach from shared memory
        i++;

        //destroy the shared memory if null
        sem_post(x2);
    }
    shmdt(str);
    // sem_close(x1);
    // sem_close(x2);
    shmctl(shmid, IPC_RMID, 0);
    sem_destroy(x1);
    sem_destroy(x2);
}