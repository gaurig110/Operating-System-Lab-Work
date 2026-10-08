//Write a C program that accepts an integer n, uses child processes to print the first n 
//Fibonacci terms and calculate n!, while the original parent calculates the sum of the 
//first n natural numbers. Use wait() to synchronize the processes.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    int n;
    scanf("%d",&n);
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
        for (int i=1;i<=n;i++) {
            printf("%d ",a);
            c=a+b;
            a=b;
            b=c;
        }
        printf("\n");
        pid_t pid2 = fork();

        if (pid2 == 0) {
        long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %lld\n", n, fact);
        exit(0);
    }
    else
    {
        wait(&status);
        printf("Sum : %d\n", n*(n-1)/2);
    }
    return 0;
}