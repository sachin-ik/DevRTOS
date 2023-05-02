//add #ifdef for include file
#ifndef TASK_H

#define TASK_H

#include <stdint.h>

#define MAX_TASKS 10

#include "queue.h"
#include "DevRTOSConfig.h"

typedef enum
{
    RUNNING = 0,
    READY,
    BLOCKED,
    SUSPENDED
} taskState_t;


typedef struct tcb
{
    uint32_t *stackPtr;
    uint32_t stackSize;
    uint32_t taskId;
    uint32_t taskPriority;
    uint32_t taskState;
    void (*taskFunction)(void);
    void *taskFunctionArgs;
    uint32_t taskFunctionReturnValue;
    uint32_t taskFunctionReturnStatus;
} tcb_t;


tcb_t* createTask(void (*taskFunction)(void), uint32_t *stack, uint32_t stackSize, uint32_t taskPriority);

void taskScheduler();
void taskInit();
#endif