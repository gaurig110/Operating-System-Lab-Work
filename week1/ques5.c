//Write a C program that accepts the number of Fibonacci terms and a number for factorial calculation, 
//then uses fork() so that the child prints the Fibonacci series and the parent calculates 
//and prints the factorial.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    int fibo;
    scanf("%d",&fibo);
    int fact;
    scanf("%d",&fact);
    pid_t pid;
    pid = fork();
    int status;
    if(pid<0)
    {
        printf("Fork failed\n");
    }
    else if(pid==0)
    {
        int a=0,b=1,c;
        printf("Fibonacci Series:\n");
        for (int i=1;i<=fibo;i++) {
            printf("%d ",a);
            c=a+b;
            a=b;
            b=c;
        }
        printf("\n");
    }
    else
    {
        int pro=1;
        for (int i=1; i<=fact; i++) {
            pro *= i;
        }
        printf("Factorial : %d\n", pro);
    }
    return 0;
}