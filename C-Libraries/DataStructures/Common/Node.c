//
//  Node.c
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//  

#include "Node.h"
#include <string.h>

struct Node node_constructor(void *data, unsigned long size)
{
    if (size < 1)
    {
        printf("Invalid data size for node...\n");
        exit(1);
    }
    struct Node node;
    
    node.data = malloc(size);           //size is the physical dimension (4 for int, 1 for char, ...)
    memcpy(node.data, data, size);      
    node.next = NULL;
    node.previous = NULL;
    return node;
}

void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}