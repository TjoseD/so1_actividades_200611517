#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

#define N_HILOS 20

void *hola_hilo(void *tid){
    printf("Hola del thread = %d, pid:%d\n",tid,getpid()); while(1);
    pthread_exit(NULL);
}

int main(){
    pthread_t hilos[N_HILOS];
    pthread_t tid = 0;
    pid_t pid ;
    int  estado ;

    pid = fork();
    if (pid > 0){
        printf("Proceso padre.. PID: %d, getpid: %d\n ", pid, getpid()); while(1);
    }else  if ( pid == 0){ /* procesos hijos */
           tid = tid + 1; 
        fork();
        estado = pthread_create(&hilos[tid], NULL, hola_hilo, (void *)tid);
        printf("Proceso hijo.. PID: %d , getpid:  %d\n",pid, getpid()); while(1); 
        if (0 != estado){
            printf("Oops. pthread_create retorno un codigo de error %d\n", estado);
            exit(-1);
        }
    }else{
        printf("Error al crear el proceso hijo.ņ");
    } 
    fork();
    printf("Proceso otro.. PID: %d , getpid: %d\n", pid, getpid()); while(1);
    return 0;
}