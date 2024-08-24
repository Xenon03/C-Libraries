//
//  Queue.c
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//

#include "Queue.h"

void push(struct Queue *queue, void * data, unsigned long size);
void * peek(struct Queue *queue);
void pop(struct Queue *queue);

struct Queue queue_constructor()
{
    struct Queue queue;
    queue.list = linked_list_constructor();

    queue.push = push;
    queue.peek = peek;
    queue.pop = pop;
    
    return queue;
}

void queue_destructor(struct Queue *queue)
{
    linked_list_destructor(&queue->list);
}

void push(struct Queue *queue, void * data, unsigned long size) 
{
    queue->list.insert(&queue->list, queue->list.length, data, size);
}

void * peek(struct Queue *queue)
{
    if (queue->list.length == 0) {
        printf("Queue is empty, cannot pop.\n");
        return NULL;
    }
    void *data = queue->list.retrieve(&queue->list, 0);
    return data;
}

void pop(struct Queue *queue) 
{ 
    if (queue == NULL || queue->list.length == 0) {
        printf("Queue is empty, cannot pop.\n");
        return;
    }
    queue->list.remove(&queue->list, 0);
    return;
}

