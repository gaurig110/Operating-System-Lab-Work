//Write a C program in which the parent calculates the sum of a fixed array, 
//sends the sum to the child through a pipe, and the child checks and displays 
//whether the received sum is prime.

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    int arr[]={1,2,3,4,5};
    int fd[2];
    int p = pipe(fd);
    if(p<0){
        printf("Pipe error");
        return(1);
    }
    pid_t pid = fork();
    if(pid < 0){
        printf("Fork failed\n");
        return 1;
    }
    else if(pid == 0){
        int recSum;
        close(fd[1]);
        read(fd[0],&recSum,sizeof(recSum));
        close(fd[0]);
        int flag=0;
        if(recSum < 2) flag=1;
        else{
            for(int i=2;i*i<recSum;i++){
                if(recSum%i==0){
                    flag=1;break;
                }
            }
        }
        flag?printf("Sum not prime"):printf("Sum is prime");
        exit(0);
    }
    else{
        int sum=0;
        for(int i=0;i<5;i++){
            sum+=arr[i];
        }
        close(fd[0]);
        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}