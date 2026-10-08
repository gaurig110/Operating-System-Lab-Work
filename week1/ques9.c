//Write a C program in which the child process terminates with exit status 10, 
//and the parent uses wait(), WIFEXITED(), and WEXITSTATUS() to read and 
//display the child's exit status.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    int status;
    pid_t pid=fork();
    if(pid<0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child exiting with status 10\n");
        exit(10);
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("Parent received exit status = %d\n",WEXITSTATUS(status));
        }
    }

    return 0;
}