#include <unistd.h>     // sleep
#include <pthread.h>    // threads
#include <stdio.h>

// Tempo global usado no aging e no deadline
int tempo = 0;
// Controle da thread
int runThread = 1;
// Controle da thread
int threadON = 0;

void* thread_timer(){
    while(runThread == 1){
        sleep(0.1);
        tempo++;
        //printf("\nTempo atual: %d\n", tempo);
    }
}

void inicia_timer(pthread_t timer){
    if(threadON == 0){
        pthread_create(&timer, NULL, thread_timer, NULL);
    }else{
        if(runThread == 0){
            runThread = 1;
        }
    }
}

void pausa_thread(){
    runThread = 0;
}

void deleta_timer(pthread_t timer){
    pthread_cancel(timer);
}