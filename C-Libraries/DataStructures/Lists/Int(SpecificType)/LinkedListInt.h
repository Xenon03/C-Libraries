//
//  LinkedListInt.h
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//

#ifndef LinkedListInt_h
#define LinkedListInt_h

#include "NodeInt.h"
#include <stdio.h>
struct LinkedList_int
{
    struct Node_int *head;
    int length;

    //generalized methods
    void (*insert)(int index, int data, struct LinkedList_int *linked_list);
    void (*remove)(int index, struct LinkedList_int *linked_list);
    int (*retrieve)(int index, struct LinkedList_int *linked_list);
};

struct LinkedList_int linked_list_int_constructor();

#endif /* LinkedListInt_h */