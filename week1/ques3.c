//Write a C program to create a child process using fork() 
//and display separate messages identifying the parent process and child process.
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
        printf("I am the child process.\n");
    }
    else
    {
        printf("I am the parent process.\n");
    }
    return 0;
}