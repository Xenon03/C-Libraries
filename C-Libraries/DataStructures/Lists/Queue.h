//
//  Queue.h
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//

#ifndef Queue_h
#define Queue_h

#include "LinkedList.h"

struct Queue
{
    struct LinkedList list;
    
    void (*push)(struct Queue *queue, void *data, unsigned long size);
    void * (*peek)(struct Queue *queue);
    void (*pop)(struct Queue *queue); //retrieves a void pointer (data)
};

struct Queue queue_constructor(void);
void queue_destructor(struct Queue *queue);


#endif /* Queue_h */