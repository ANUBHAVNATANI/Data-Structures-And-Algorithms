#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//global counter

//mutex lock

int counter = 0;
pthread_mutex_t lock;

void *funt()
{
    pthread_mutex_lock(&lock);
    ++counter;
    printf("thread %d has started \n", counter);
    sleep(1);
    printf("therad %d has finished \n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void main()
{
    pthread_t t1, t2;
    int r = pthread_mutex_init(&lock, NULL);
    if (r != 0)
    {
        printf("Error");
        exit(0);
    }
    r = pthread_create(&t1, NULL, funt, NULL);
    if (r != 0)
    {
        printf("Error");
        exit(0);
    }
    r = pthread_create(&t2, NULL, funt, NULL);
    if (r != 0)
    {
        printf("Error");
        exit(0);
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}