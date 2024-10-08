//
//  LinkedListInt.c
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//

#include "LinkedListInt.h"
#include <stdlib.h>

struct Node_int * create_node_int(int data);
void destroy_node_int(struct Node_int *node_to_destroy);

struct Node_int * iterate_int(int index, struct LinkedList_int *linked_list);
void insert_node_int(int index, int data, struct LinkedList_int *linked_list);
void remove_node_int(int index, struct LinkedList_int *linked_list);
int retrieve_data_int(int index, struct LinkedList_int *linked_list);

struct LinkedList_int linked_list_int_constructor()
{
    struct LinkedList_int new_list;
    new_list.head = NULL;
    new_list.length = 0;

    //  The user won't be able to call *_int directly, but will be forced to use the default methods
    //  (insert, remove, retrieve, constructor)
    new_list.insert = insert_node_int;
    new_list.remove = remove_node_int;
    new_list.retrieve = retrieve_data_int;
    
    return new_list;
}

struct Node_int * create_node_int(int data)
{
    struct Node_int *new_node_address = (struct Node_int *)malloc(sizeof(struct Node_int));
    struct Node_int new_node_instance;
    new_node_instance.data = data;
    new_node_instance.next = NULL;
    *new_node_address = new_node_instance;
    return new_node_address;
}

void destroy_node_int(struct Node_int *node_to_destroy)
{
    free(node_to_destroy);
}

struct Node_int * iterate_int(int index, struct LinkedList_int *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bound...");
        exit(9);
    }
    struct Node_int *cursor = linked_list->head;
    for(int i=0;i<index;i++)
    {
        cursor = cursor->next;
    }

    return cursor;
}

void insert_node_int(int index, int data, struct LinkedList_int *linked_list)
{
    if (index < 0 || index > linked_list->length) 
    {
        printf("Index out of bound...");
        exit(9);
    }

    struct Node_int *node_to_insert = create_node_int(data);
    struct Node_int *cursor;
    if (index == 0) {
        cursor = linked_list->head;
    } else {
        cursor = iterate_int(index - 1, linked_list);
    }
    node_to_insert->next = cursor->next;
    cursor->next = node_to_insert;
    linked_list->length++;
}

void remove_node_int(int index, struct LinkedList_int *linked_list)
{
    if (index < 0 || index >= linked_list->length) 
    {
        printf("Index out of bound...");
        exit(9);
    }
    struct Node_int *node_to_remove;
    if (index == 0){
        node_to_remove = iterate_int(0, linked_list);
        linked_list->head = node_to_remove->next;
    } else {
        struct Node_int *cursor = iterate_int(index - 1, linked_list);
        node_to_remove = cursor->next;
        cursor->next = node_to_remove->next;
    }
    destroy_node_int(node_to_remove);
    linked_list->length--;
}

int retrieve_data_int(int index, struct LinkedList_int *linked_list)
{
    if (index < 0 || index > linked_list->length) 
    {
        printf("Index out of bound...");
        exit(9);
    }
    struct Node_int *cursor = iterate_int(index,linked_list);
    return cursor->data;
}