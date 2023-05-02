#ifndef QUEUE_H

#define QUEUE_H

#include<stdint.h>
#include"DevRTOSConfig.h"
//q: queue data structure
//q->head: pointer to the head of the queue
//q->tail: pointer to the tail of the queue
//q->size: size of the queue
//q->max_size: maximum size of the queue
//q->data: array of data
typedef struct queue {
    void*     queueBuffer;
    uint32_t  queueDataSize;
    uint32_t  queueHead;
    uint32_t  queueTail;
    uint32_t  queueSize;
    uint32_t  queueMaxSize;
    void*     data;
} queue_t;

queue_t* q_create(uint32_t qsize, uint32_t data_size);
int q_delete(queue_t* queue);
int q_enqueue(queue_t* queue, void* data);
int q_dequeue(queue_t* queue, void* data);


#endif