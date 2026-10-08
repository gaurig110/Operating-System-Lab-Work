//Write a C program to demonstrate an orphan process by terminating 
//the parent while the child continues execution. Display the child's 
//parent process ID before and after the parent terminates.

#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        printf("Fork failed\n");
        return 1;
    }
    else if(pid == 0){
        printf("Child: My PID is %d and my Parent's PID is %d.\n", getpid(), getppid());
        sleep(5);
        printf("Child: After parent termination, my Parent's PID is %d.\n", getppid());
    }
    else{
        printf("Parent: My PID is %d and my Child's PID is %d.\n", getpid(), pid);
    }
    return 0;
}