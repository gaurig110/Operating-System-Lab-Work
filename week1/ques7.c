//Write a C program using fork() in which the parent prints even numbers 
//from 2 to 20 and the child prints odd numbers from 1 to 19.
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
        for(int i=1;i<=19;i+=2){
            printf("%d ",i);
        }
        printf("\n");
    }
    else
    {
        for(int i=2;i<=20;i+=2){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}