/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "task.h"
#include "list.h"
#include "schedule_rr.h"
//#include "schedule_rr_p.h"
#include "thread.h"

#define SIZE    100

int main(int argc, char *argv[])
{
    pthread_t timer;
    

    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    char * arquivo = "rr-schedule_pri.txt";
    in = fopen(arquivo,"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));
        add(name,burst);
        //add(name,priority,burst);
        free(temp);
    }

    fclose(in);
    inicia_timer(timer);
    // invoke the scheduler
    schedule();

    return 0;
}
