#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>


int main(){
    pid_t pid_hijo ;
   
    pid_hijo = fork();
    switch (pid_hijo){
        case 0:{ printf("Proceso HIJO PID: %d,  parent_PID: %d\n ", getpid(), getppid()); break;}
        case -1: {  printf(" errno = %d\n", errno); perror("fork"); break; }
        default: { // proceso padre
            printf("Proceso PADRE  PID: %d,  parent_PID: %d\n ", getpid(), getppid()); 
            sleep(300);
            wait(NULL);
        }
    }
}





