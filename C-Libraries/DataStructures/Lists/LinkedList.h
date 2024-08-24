//
//  LinkedList.h
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include "../Common/Node.h"

struct LinkedList
{
    struct Node *head;
    int length;

    //generalized methods
    void (*insert)(struct LinkedList *linked_list, int index, void *data, unsigned long size);
    void (*remove)(struct LinkedList *linked_list, int index);
    void * (*retrieve)(struct LinkedList *linked_list, int index);
    // Sorting and searching the list (bubble sort).
    void (*sort)(struct LinkedList *linked_list, int (*compare)(void *a, void *b));
    // Binary search (requires the list be sorted).
    short (*search)(struct LinkedList *linked_list, void *query, int (*compare)(void *a, void *b));
};

struct LinkedList linked_list_constructor(void);
void linked_list_destructor(struct LinkedList *linked_list);

#endif /* LinkedList_h */