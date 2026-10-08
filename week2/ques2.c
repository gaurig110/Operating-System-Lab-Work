//Write a C program that accepts an integer n, uses the child process 
//to print Fibonacci numbers up to n, and uses the parent process to 
//print Armstrong numbers detected by the program from 1 through n.

#include <stdio.h>
#include <unistd.h>
#include <math.h>
int isArmstrong(int num) {
    int originalNum = num,sum = 0,digits = 0;
    while (num!=0) {
        num/=10;
        digits++;
    }
    num=originalNum;
    while (num != 0){
        int digit=num%10;
        sum+=pow(digit,digits);
        num/=10;
    }
    return sum==originalNum;
}
int main() {
    int n;
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        int a=0,b=1,c;
        printf("Child: Fibonacci numbers up to %d: ", n);
        for(int i=1;i<=n;i++) {
            printf("%d ",a);
            c=a+b;
            a=b;
            b=c;
        }
        printf("\n");
    } else {
        wait(NULL);
        printf("Parent: Armstrong numbers from 1 to %d: ", n);
        for (int i = 1; i <= n; i++) {
            if (isArmstrong(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}