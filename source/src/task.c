#include<stdlib.h>
#include<stdint.h>

#include "task.h"

//q: function to create a task?
void createTask(tcb_t *tcb, void (*taskFunction)(void), uint32_t *stackPtr, uint32_t stackSize, uint32_t taskPriority)
{
    tcb->stackPtr = stackPtr;
    tcb->stackSize = stackSize;
    tcb->taskPriority = taskPriority;
    tcb->taskState = READY;
    tcb->taskFunction = taskFunction;
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


