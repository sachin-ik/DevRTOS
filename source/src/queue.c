#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

#include "queue.h"

//q: function to create queue using structs in queue.h
//q: returns pointer to queue
queue_t* q_create(uint32_t qsize, uint32_t data_size)
{
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    queue->queueMaxSize = qsize;
    queue->queueDataSize = data_size;
    queue->queueHead = 0;
    queue->queueTail = 0;
    queue->data = (void*)malloc(data_size*qsize);
    return queue;
}

//q: function to delete queue
//q: returns 0 if successful, -1 if not
int q_delete(queue_t* queue)
{
    if(queue->data != NULL)
    {
        free(queue->data);
        queue->data = NULL;
    }
    if(queue != NULL)
    {
        free(queue);
        queue = NULL;
    }
    return 0;
}

//q: function to enqueue data into queue
//q: returns 0 if successful, -1 if not
int q_enqueue(queue_t* queue, void* data)
{
    if(queue->queueSize == queue->queueMaxSize)
    {
        return -1;
    }
    else
    {
        uint32_t* x = (uint32_t*)queue->data;
        x[queue->queueTail] = *(uint32_t*)data;
        queue->queueTail = (queue->queueTail + 1) % queue->queueMaxSize;
        queue->queueSize++;
        return 0;
    }
}

//q: function to dequeue data from queue
//q: returns 0 if successful, -1 if not
int q_dequeue(queue_t* queue, void* data)
{
    if(queue->queueSize == 0)
    {
        return -1;
    }
    else
    {
        uint32_t* x = (uint32_t*)queue->data;
        *(uint32_t*)data = x[queue->queueHead];
        queue->queueHead = (queue->queueHead + 1) % queue->queueMaxSize;
        queue->queueSize--;
        return 0;
    }
}

