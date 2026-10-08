//Write a C program in which the parent creates input.txt, writes a name, 
//university roll number, and class into it, and the child opens the file, 
//reads its contents, and displays them.


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

int main(){
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
        char recFile[50];
        close(fd[1]);
        read(fd[0],recFile,sizeof(recFile));
        close(fd[0]);

        FILE *fp = fopen(recFile,"r");
        if(fp==NULL){
            printf("File opening failed\n");
            return 1;
        }
        char buffer[256];
        while(fgets(buffer,sizeof(buffer),fp)!=NULL){
            printf("%s",buffer);
        }
        fclose(fp);
        exit(0);
    }
    else{
        char fileName[]="input.txt";
        FILE *fp = fopen(fileName,"w");
        if(fp==NULL){
            printf("File creation failed\n");
            return 1;
        }
        fprintf(fp,"Name : Gauri Goel\n");
        fprintf(fp,"Uni. Roll no : 2025196\n");
        fprintf(fp,"Class Roll no : 25\n");
        fclose(fp);
        
        close(fd[0]);
        write(fd[1],fileName,strlen(fileName)+1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}