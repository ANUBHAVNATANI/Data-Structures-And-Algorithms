#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void funtioncall()
{
    int c = 0;
    c = fork();
    if (c == 0)
    {
        printf("\nI am the first chlid with pid %d \n", getpid());
        int d = 0;
        d = fork();
        if (d == 0)
        {
            printf("\nI am the second super chlid with pid %d \n", getpid());

            int e = 0;
            e = fork();
            if (e == 0)
            {
                printf("\nI am the third super chlid with pid %d \n", getpid());

                int f = 0;
                f = fork();
                if (f == 0)
                {
                    printf("\nI am the forth super chlid with pid %d \n", getpid());
                }
            }
        }
    }
    else
    {
        printf("\nI am the parent with pid %d \n ", getpid());
    }
}

void main()
{
    //pthread_t thread_1;
    funtioncall();
}