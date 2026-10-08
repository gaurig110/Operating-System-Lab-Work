//Write a C program in which the child process prints the numbers 1 to 5, 
//while the parent process waits for the child to finish using wait() and then prints a completion message.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid = fork();
    int status;
    if(pid<0)
    {
        printf("Fork failed\n");
    }
    else if(pid==0)
    {
        for(int i=0;i<5;i++){
            printf("%d ",i+1);
        }
        printf("\nI am the child process.Exiting...\n");
        exit(0);
    }
    else
    {
        wait(&status);
        printf("I am the parent process. Child has finished.\n");
    }
    return 0;
}