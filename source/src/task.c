#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

#include "task.h"
#include "DevRTOSConfig.h"

queue_t* priorityQueue[DEVRTOS_MAX_PRIORITY_LEVELS];

void taskInit()
{
    for(int i = 0; i < DEVRTOS_MAX_PRIORITY_LEVELS; i++)
    {
        priorityQueue[i] = q_create(DEVRTOS_MAX_TASKS, sizeof(tcb_t*));
    }
}

tcb_t* createTask(void (*taskFunction)(void), uint32_t *stackPtr, uint32_t stackSize, uint32_t taskPriority)
{
    printf("create task\n");
    tcb_t* tcb = (tcb_t*)malloc(sizeof(tcb_t));
    tcb->stackPtr = stackPtr;
    tcb->stackSize = stackSize;
    tcb->taskPriority = taskPriority;
    tcb->taskState = READY;
    tcb->taskFunction = taskFunction;
    printf("enqueue task\n");
    q_enqueue(priorityQueue[taskPriority], &tcb);
    return tcb;
}

//q: function to delete a task?
void deleteTask(tcb_t *tcb)
{
    tcb->stackPtr = NULL;
    tcb->stackSize = 0;
    tcb->taskPriority = 0;
    tcb->taskState = 0;
    tcb->taskFunction = NULL;
}


void taskScheduler()
{
    printf("task scheduler\n");
    for(;;)
    {
        for(int i = 0; i < DEVRTOS_MAX_PRIORITY_LEVELS; i++)
        {
            tcb_t* tcb = (tcb_t*)malloc(sizeof(tcb_t));

            if(q_dequeue(priorityQueue[i], &tcb) == 0)
            {
                printf("Run task with priority = %d\n", i);
                tcb->taskFunction();
                //q_enqueue(priorityQueue[i], &tcb);
            }
            if(tcb != NULL)
                free(tcb);
            if(i==10)return;
        }
    }
}