
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "thread.h"
#include "task.h"
#include "list.h"
#include "schedule_rr.h"
//#include "schedule_rr_p.h"
#include "CPU.h"

struct node *Filas;

void iniciarlizarFilas(){
    Filas = NULL;
}

struct Task* taskCreate(const char *name, int burst) {
    Task *NewT = malloc(sizeof(struct Task));
    if (!NewT) {
        perror("Erro ao alocar Task");
        exit(1);
    }
    NewT->name = strdup(name);
    NewT->burst = burst;
    return NewT;
}

void add(char *name, int burst) {
    Task *NewT = taskCreate(name, burst);
    insert(&Filas, NewT);

}

// invoke the scheduler
void schedule(){
         while(Filas != NULL){
            struct node *atual = pop(&Filas);

            // Verificação de segurança
            if(atual == NULL || atual->task == NULL) {
                if(atual) free(atual);
                continue;
            }

            //int tempoExecutado = (atual->task->burst < QUANTUM) ? atual->task->burst : QUANTUM;
            int contador = QUANTUM + tempo;
            while(contador > tempo && atual->task->burst > 0){
                atual->task->burst -= 1;
                sleep(0.1);
                run(atual->task,1); // Permite visualizar a execução da tarefa
            }

            //Simula o ganho da CPU e decremento do QUANTUM
            if(atual->task->burst > 0){
               insert_end(&Filas, atual);
            }else{
               printf("Tarefa %s finalizada!\n", atual->task->name);
               free(atual->task);
               free(atual);
            }
      }
}

