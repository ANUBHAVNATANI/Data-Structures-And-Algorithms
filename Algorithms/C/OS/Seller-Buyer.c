// m number of sellers
// n number of movie tickets to sell
// m<n

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int m = 3;
int n = 21;
int curr = 1;
sem_t ticktes;
int value;
int totsold[3];
void *selling(void *par)
{
    while (1)
    {
        if (n <= 0)
        {
            break;
        }
        sem_wait(&ticktes);
        n--;
        if (n < 0)
        {
            sem_post(&ticktes);
            break;
        }
        printf("Seller %d sold one \n", (int)par + 1);
        totsold[(int)par]++;

        printf("Total tickets remained %d \n", n);
        sem_post(&ticktes);
        sleep(rand() % 2 + 0.5);
    }
}
int main()
{
    pthread_t sellers[m];
    for (int i = 0; i < m; i++)
    {
        totsold[i] = 0;
    }
    int i = 0;
    sem_init(&ticktes, 0, 1);
    while (i < m)
    {
        pthread_create(&sellers[i], NULL, &selling, (void *)i);
        i++;
    }
    i = 0;
    while (i < m)
    {
        pthread_join(sellers[i], NULL);
        i++;
    }
    for (int i = 0; i < m; i++)
    {
        printf("Total tickets sold by a %d seller is %d \n", (i + 1), totsold[i]);
        sem_destroy(&ticktes);
    }
}