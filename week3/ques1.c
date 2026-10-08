//Write a C program that accepts an array of integers, creates a child process, 
//calculates the sum of the array in the child, checks whether the sum is prime, 
//and makes the parent wait for the child to complete.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        int isPrime = 1;
        if (sum<=1) {
            isPrime=0;
        } else {
            for (int i=2; i*i<=sum; i++) {
                if (sum%i == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }
        printf("Child: Sum = %d, Is Prime = %s\n", sum, isPrime ? "Yes" : "No");
    } else {
        wait(NULL);
        printf("Parent process completed.\n");
    }
    return 0;
}