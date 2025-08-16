
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "thread.h"
#include "task.h"
#include "list.h"
#include "schedule_rr_p.h"
#include "CPU.h"

struct node *Filas[MAX_PRIORITY];

void iniciarlizarFilas(){
   for(int i = 0; i < MAX_PRIORITY; i++){
      Filas[i] = NULL;
   }
}

struct Task* taskCreate(const char *name, int priority, int burst) {
    Task *NewT = malloc(sizeof(struct Task));
    if (!NewT) {
        perror("Erro ao alocar Task");
        exit(1);
    }
    NewT->name = strdup(name);
    NewT->priority = priority;
    NewT->burst = burst;
    return NewT;
}

void add(char *name, int priority, int burst) {
    Task *NewT = taskCreate(name, priority, burst);
    if (priority >= 1 && priority <= 10) {
        insert(&Filas[priority - 1], NewT);
    } else {
        printf("Erro: prioridade %d inválida. Deve estar entre 1 e 10.\n", priority);
        free(NewT);
    }
}


// invoke the scheduler
void schedule(){
   for(int i = 0; i < MAX_PRIORITY; i++){
         while(Filas[i] != NULL){

            //Verifica se entrou uma nova task em tempo de execução
            for (int j = 0; j < i; j++) {
                if (Filas[j] != NULL) {
                    i = j;  // diminui para que i++ volte para prioridade correta
                    break;
                }
            }

            struct node *atual = pop(&Filas[i]);
            
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
            //atual->task->burst -= tempoExecutado; 
            if(atual->task->burst > 0){
               insert_end(&Filas[i], atual);
            }else{
               printf("Tarefa %s finalizada!\n", atual->task->name);
               free(atual->task);
               free(atual);
            }
            //traverse(Filas[i]);  // exibe o estado atual da fila
      }
   }
}

