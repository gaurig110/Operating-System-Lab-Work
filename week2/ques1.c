//Write a C program that accepts an integer and uses fork() so that the 
//child checks whether the number is prime, while the parent calculates 
//and displays its factorial after waiting for the child.

#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int main(){
    int num;
    scanf("%d", &num);
    pid_t pid = fork();
    if(pid < 0){
        printf("Fork failed\n");
        return 1;
    }
    else if(pid == 0){
        int isPrime = 1;
        if(num <= 1) isPrime = 0;
        for(int i = 2; i*i <= num; i++){
            if(num % i == 0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
            printf("Child: %d is a prime number.\n", num);
        else
            printf("Child: %d is not a prime number.\n", num);
    }
    else{\
        wait(NULL);
        long long factorial = 1;
        for(int i = 1; i <= num; i++){
            factorial *= i;
        }
        printf("Parent: Factorial of %d is %lld.\n", num, factorial);
    }
    return 0;
}