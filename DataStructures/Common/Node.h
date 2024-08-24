//
//  Node.h
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//  
//  Generic, it's going to fit more situations. If you need a specific type, 
//  it's going to be more efficient to create the specific version
//

#ifndef Node_h
#define Node_h

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node        
{
    void *data;
    struct Node *next;
    struct Node *previous;   //no effect on linked lists, will be used for binary trees. There, next and previous should be intended as right and left
};

struct Node node_constructor(void *data, unsigned long size);
void node_destructor(struct Node *node);

#endif /* Node_h */