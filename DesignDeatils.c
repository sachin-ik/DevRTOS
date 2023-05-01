//This doc contains the requirements and design details of a Real Time Operating system.

//q:6 importants tasks of a RTOS?
//1. Task Management -> task creation, task deletion, task suspension, task resumption, task priorities.
//2. Memory Management -> dynamic memory allocation (heap)
//3. Time Management -> timers, systicks.
//4. Communication Management -> queues, semaphores, mutexes.
//5. Interrupt Management -> interrupt handlers, interrupt priorities.
//6. Device Management -> device drivers, device configuration.

//q: states of an RTOS?
//1. Running -> the task is currently running.
//2. Ready -> the task is ready to run but is not currently running.
//3. Blocked -> the task is blocked and cannot run.
//4. Suspended -> the task is suspended and cannot run.

//q: data structure of a task control block?
//1. Task ID -> unique ID of the task.
//2. Task Priority -> priority of the task.
//3. Task State -> state of the task.
//4. Task Stack Pointer -> pointer to the task stack.
//5. Task Stack -> stack of the task.
//6. Task Function -> function of the task.
//7. Task Function Arguments -> arguments of the task function.
//8. Task Function Return Value -> return value of the task function.
//9. Task Function Return Status -> return status of the task function.

//q: write a task control block structure in c?
typedef struct tcb
{
    uint32_t *stackPtr;
    uint32_t *stack;
    uint32_t taskID;
    uint32_t taskPriority;
    uint32_t taskState;
    void (*taskFunction)(void);
    void *taskFunctionArgs;
    uint32_t taskFunctionReturnValue;
    uint32_t taskFunctionReturnStatus;
} tcb_t;

//q: scheduler function to run the highest priority task for above task control block structure?
void scheduler(void)
{
    uint32_t highestPriority = 0;
    uint32_t highestPriorityTaskIndex = 0;
    for (uint32_t i = 0; i < MAX_TASKS; i++)
    {
        if (tcb[i].taskPriority > highestPriority)
        {
            highestPriority = tcb[i].taskPriority;
            highestPriorityTaskIndex = i;
        }
    }
    tcb[highestPriorityTaskIndex].taskFunction();
}

//q: interrupt service routine to call this scheduler function?
void SysTick_Handler(void)
{
    scheduler();
}

//q: function to create a task?
void createTask(tcb_t *tcb, void (*taskFunction)(void), uint32_t *stack, uint32_t stackSize, uint32_t taskPriority)
{
    printf("Creating task with priority %d\n", taskPriority);
    tcb->stackPtr = &stack[stackSize - 16];
    tcb->stack = stack;
    tcb->taskPriority = taskPriority;
    tcb->taskState = READY;
    tcb->taskFunction = taskFunction;
}

//q: function to delete a task?
void deleteTask(tcb_t *tcb)
{
    tcb->stackPtr = NULL;
    tcb->stack = NULL;
    tcb->taskPriority = 0;
    tcb->taskState = 0;
    tcb->taskFunction = NULL;
}

//q:enums for rtos states?
typedef enum
{
    RUNNING,
    READY,
    BLOCKED,
    SUSPENDED
} taskState_t;





