#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#include "queue.h"
#include "task.h"
// struct test_struct
// {
//     uint32_t x;
//     uint32_t y;
//     uint32_t z;
// };

//q: function to test queue
// void testQueue()
// {
//     queue_t* queue = q_create(5, sizeof(struct test_struct));

//     struct test_struct* x = (struct test_struct*)malloc(sizeof(struct test_struct));
//     struct test_struct* y = (struct test_struct*)malloc(sizeof(struct test_struct));
//     struct test_struct* z = (struct test_struct*)malloc(sizeof(struct test_struct));
//     struct test_struct* a = (struct test_struct*)malloc(sizeof(struct test_struct));
//     struct test_struct* b = (struct test_struct*)malloc(sizeof(struct test_struct));
//     struct test_struct* c = (struct test_struct*)malloc(sizeof(struct test_struct));
//     x->x = 1;
//     y->x = 2;
//     z->x = 3;
//     a->x = 4;
//     b->x = 5;
//     c->x = 6;
//     q_enqueue(queue, x);
//     q_enqueue(queue, y);
//     q_enqueue(queue, z);
//     q_enqueue(queue, a);
//     q_enqueue(queue, b);
//     q_enqueue(queue, c);
//     printf("%d\n", q_size(queue));
//     struct test_struct* data = (struct test_struct*)malloc(sizeof(struct test_struct));
//     q_dequeue(queue, data);
//     printf("%d\n", data->x);
//     q_dequeue(queue, data);
//     printf("%d\n", data->x);
//     q_dequeue(queue, data);
//     printf("%d\n", data->x);
//     q_dequeue(queue, data);
//     printf("%d\n", data->x);
//     q_dequeue(queue, data);
//     printf("%d\n", data->x);

//     q_delete(queue);
//     free(data);
// }


tcb_t* task1;

void task1_function()
{
    printf("Task 1\n");
}

void testQueue()
{
    printf("Test Queue\n");
    queue_t* queue = q_create(5, sizeof(tcb_t*));
    task1 = (tcb_t*)malloc(sizeof(tcb_t));
    printf("create task\n");
    createTask(task1, &task1_function, NULL, 100, 1);
    
    q_enqueue(queue, &task1);
    tcb_t* data =(tcb_t*)malloc(sizeof(tcb_t));
    q_dequeue(queue, &data);
    printf("%d\n", data->taskPriority);
    q_delete(queue);
    free(data);
}

//gcc command build this file
//gcc -Wall -Werror -g -o queue queue.c
//gcc -o queue queue.c -iquote ../inc/
int main()
{
    testQueue();
    return 0;
}