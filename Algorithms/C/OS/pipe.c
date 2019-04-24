//program to demostrate the use of pipe
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define Buf_s 25
#define Read_end 0
#define Write_end 1
void main()
{
    char w_msg[Buf_s];
    char r_msg[Buf_s];
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1)
    {
        printf("pipe failed");
    }
    pid = fork();
    if (pid < 0)
    {
        printf("fork faild");
    }
    if (pid > 0)
    {
        close(1);
        dup(fd[Write_end]);
        close(fd[Read_end]);
        gets(w_msg);
        write(fd[Write_end], w_msg, strlen(w_msg) + 1);
    }
    else
    {
        close(0);
        dup(fd[Read_end]);
        close(fd[Write_end]);
        read(fd[Read_end], r_msg, 100);
        printf("%s\n", r_msg);
    }
}