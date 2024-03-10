#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMERO_DE_HILOS 10

void *print_hola_mundo(void *tid){
    printf("Hola mundo, Saludos del hilo %d\n",tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    /* crea 10 hilos */
    pthread_t hilos[NUMERO_DE_HILOS];
    int estado, i;
    for(i= 0; i<NUMERO_DE_HILOS; i++){
        printf("Desde Main, Creando el hilo %d\n", i);
        estado = pthread_create(&hilos[i], NULL, print_hola_mundo, (void *)i);
        if (0 != estado){
            printf("Oops. pthread_create retorno un codigo de error %d\n", estado);
            exit(-1);
        }
    }
    exit(NULL);
}
