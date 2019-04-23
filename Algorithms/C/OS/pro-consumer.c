#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
sem_t empty;
sem_t full;
pthread_mutex_t l;

void *prd(void *m)
{
    while (1)
    {
        sem_wait(empty);
        pthread_mutex_lock(&l);
        printf("producer is producing\n");
        sleep(1);
        pthread_mutex_unlock(&l);
        sem_post(full);
    }
}

void *cons(void *m)
{
    while (1)
    {
        sem_wait(full);
        pthread_mutex_lock(&l);
        printf("consumer is consuming\n");
        sleep(1);
        pthread_mutex_unlock(&l);
        sem_post(empty);
    }
}

void main()
{
    pthread_t prod, consumer;
    sem_init(&empty, 0, 6);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&l, NULL);
    pthread_create(&prod, NULL, prd, NULL);
    pthread_create(&consumer, NULL, cons, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_join(prod, NULL);
    pthread_join(consumer, NULL);
}