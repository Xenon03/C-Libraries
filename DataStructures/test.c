//
//  test.c
//  DataStructures
//
//  Created by Federico Balistreri on 8/17/24
//  

#include <stdlib.h>
#include <stdio.h>
#include "DataStructures/Lists/Queue.h"

int main()
{
    struct Queue list = queue_constructor();

    // Push elements to the queue
    for (int i = 0; i < 10; i++)
    {
        /* int array case
        int *x = malloc(3 * sizeof(int));
        x[0] = i;
        x[1] = i + 1;
        x[2] = i + 2;
        list.push(&list, x, Int, 3); */
        
        // int case
        int* x = (int*)malloc(sizeof(int*));
        *x = i;
        list.push(&list, x, 4);
    }

    // Pop elements from the queue
    for (int i = 0; i < 10; i++)
    {
        /*array of ints
        printf("[%d, %d, %d]\n", ((int*)list.peek(&list))[0], ((int*)list.peek(&list))[1], ((int*)list.peek(&list))[2]); */

        //int
        printf("[%d]\n", *((int*)list.peek(&list)));
        list.pop(&list);
    }

    queue_destructor(&list);  //unuseful as we pop after every peek call
    return 0;
}