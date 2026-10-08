//Write a C program using fork() in which both the parent and 
//child processes display their Process ID (PID) and Parent Process ID (PPID) using getpid() and getppid()

#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid<0)
    {
        printf("Fork failed\n");
    }
    else if(pid==0)
    {
        printf("I am the child. My PID is %d and my Parent's PID is %d.\n", getpid(), getppid());
    }
    else
    {
        printf("I am the parent. My PID is %d and my child's PID is %d.\n", getpid(), pid);
    }
    return 0;
}