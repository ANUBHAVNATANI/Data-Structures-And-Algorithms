#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int pil = 5;
pthread_t phil[5];
sem_t chopstick[6];
void pickup(int i)
{
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i + 1) % pil]);
}

void putdown(int i)
{
    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i + 1) % pil]);
}

void *philoso(void *m)
{
    while (1)
    {
        int *p = (int *)m;
        printf("philosopher %d is hungry\n", *p);
        sleep(1);
        pickup(*p);
        printf("philosopher %d in eating\n", *p);
        sleep(rand() % 10);
        putdown(*p);
        sleep(1);
        printf("philosopher %d is thinking\n", *p);
    }
}
int main()
{
    int i;
    int phi[] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 6; i++)
    {
        sem_init(&chopstick[i], 0, 1);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&phil[i], NULL, philoso, &phi[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(phil[i], NULL);
    }
    return 0;
}