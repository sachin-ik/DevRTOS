#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#include "task.h"

/* printf() output uses the UART.  These constants define the addresses of the
required UART registers. */
#define UART0_ADDRESS 	( 0x40004000UL )
#define UART0_DATA		( * ( ( ( volatile uint32_t * )( UART0_ADDRESS + 0UL ) ) ) )
#define UART0_STATE		( * ( ( ( volatile uint32_t * )( UART0_ADDRESS + 4UL ) ) ) )
#define UART0_CTRL		( * ( ( ( volatile uint32_t * )( UART0_ADDRESS + 8UL ) ) ) )
#define UART0_BAUDDIV	( * ( ( ( volatile uint32_t * )( UART0_ADDRESS + 16UL ) ) ) )
#define TX_BUFFER_MASK	( 1UL )

tcb_t* task1;

void task1_function()
{
    printf("Task 1\n");
}

tcb_t* task2;

//create task2
void task2_function()
{
    printf("Task 2\n");
}

//create task3
tcb_t* task3;
void task3_function()
{
    printf("Task 3\n");
}

//create task4
tcb_t* task4;
void task4_function()
{
    printf("Task 4\n");
}

void testQueue()
{
    printf("Test Queue\n");
    task1 = createTask( &task1_function, NULL, 100, 1);
    task2 = createTask( &task2_function, NULL, 100, 2);
    task3 = createTask( &task3_function, NULL, 100, 3);
    task4 = createTask( &task4_function, NULL, 100, 4);
}

//gcc command build this file
//gcc -Wall -Werror -g -o queue queue.c
//gcc -o queue queue.c -iquote ../inc/
int main()
{
    taskInit();
    testQueue();
    taskScheduler();
    return 0;
}