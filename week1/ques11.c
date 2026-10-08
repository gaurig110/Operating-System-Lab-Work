//Write a C program to demonstrate a zombie process by allowing the child to terminate 
//while the parent remains alive and does not immediately call wait().
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child exits.\n");
        exit(0);
    }
    else
    {
        printf("Parent sleeping for 20 seconds.\n");
        sleep(20);
    }
    return 0;
}