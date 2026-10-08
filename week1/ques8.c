//Write a C program to create three child processes. 
//Each child should print its child number, PID, and PPID. 
//The original parent should wait for all three child processes to terminate.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    for(int i=1;i<=3;i++)
    {
        pid=fork();
        if(pid<0)
        {
            printf("Fork failed\n");
            return 1;
        }
        else if(pid==0)
        {
            printf("Child %d: PID = %d, PPID = %d\n", i, getpid(), getppid());
            return 0;
        }
    }
    for(int i=1;i<=3;i++)
    {
        wait(NULL);
    }
    printf("All child processes have terminated.\n");
    return 0;
}