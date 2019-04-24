
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

sem_t mutex_l;

sem_t students[5];

sem_t agent_pp;

int resourse[5] = {0, 1, 2, 3, 4};

char studentName[5] = {'A', 'B', 'C', 'D', 'E'};

void *agent(void *arg)
{
    while (true)
    {
        sem_wait(&mutex_l);
        int d = rand() % 5;
        if (d == 1)
        {
            //all other than one is available
            sem_post(&students[d]);
        }
        else if (d == 2)
        {
            //all other than two is available
            sem_post(&students[d]);
        }
        else if (d == 3)
        {
            //all other than three is available
            sem_post(&students[d]);
        }
        else if (d == 4)
        {
            //all other than four is available
            sem_post(&students[d]);
        }
        else
        {
            //all other than zero is available
            sem_post(&students[d]);
        }
        sem_post(&mutex_l);
        sem_wait(&agent_pp);
    }
}

void *student_a(void *arg)
{
    while (1)
    {
        sleep(5);
        sem_wait(&students[0]);
        sem_wait(&mutex_l);
        printf("\n %c got the resourses and building the computer \n", studentName[0]);
        sem_post(&agent_pp);
        sem_post(&mutex_l);
    }
}

void *student_b(void *arg)
{
    while (1)
    {
        sleep(4);
        sem_wait(&students[1]);
        sem_wait(&mutex_l);
        printf("\n %c got the resourses and building the computer \n", studentName[1]);
        sem_post(&agent_pp);
        sem_post(&mutex_l);
    }
}

void *student_c(void *arg)
{
    while (1)
    {
        sleep(3);
        sem_wait(&students[2]);
        sem_wait(&mutex_l);
        printf("\n %c got the resourses and building the computer \n", studentName[2]);
        sem_post(&agent_pp);
        sem_post(&mutex_l);
    }
}

void *student_d(void *arg)
{
    while (1)
    {
        sleep(2);
        sem_wait(&students[3]);
        sem_wait(&mutex_l);
        printf("\n %c got the resourses and building the computer \n", studentName[3]);
        sem_post(&agent_pp);
        sem_post(&mutex_l);
    }
}

void *student_e(void *arg)
{
    while (1)
    {
        sleep(1);
        sem_wait(&students[4]);
        sem_wait(&mutex_l);
        printf("\n %c got the resourses and building the computer \n", studentName[4]);
        sem_post(&agent_pp);
        sem_post(&mutex_l);
    }
}

int main()
{
    sem_init(&mutex_l, 0, 1);
    sem_init(&agent_pp, 0, 0);
    sem_init(&students[0], 0, 0);
    sem_init(&students[1], 0, 0);
    sem_init(&students[2], 0, 0);
    sem_init(&students[3], 0, 0);
    sem_init(&students[4], 0, 0);
    pthread_t agent_t;
    pthread_t std_a;
    pthread_t std_b;
    pthread_t std_c;
    pthread_t std_d;
    pthread_t std_e;
    pthread_create(&agent_t, NULL, agent, NULL);
    pthread_create(&std_a, NULL, student_a, NULL);
    pthread_create(&std_b, NULL, student_b, NULL);
    pthread_create(&std_c, NULL, student_c, NULL);
    pthread_create(&std_d, NULL, student_d, NULL);
    pthread_create(&std_e, NULL, student_e, NULL);
    pthread_join(agent_t, NULL);
    pthread_join(std_a, NULL);
    pthread_join(std_b, NULL);
    pthread_join(std_c, NULL);
    pthread_join(std_d, NULL);
    pthread_join(std_e, NULL);
    return 0;
}
