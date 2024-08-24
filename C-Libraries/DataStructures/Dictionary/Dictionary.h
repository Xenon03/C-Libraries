//
//  Dictionary.h
//  DataStructures
//
//  Created by Federico Balistreri on 8/19/24
//  
//  BASED ON THE PYTHON MODEL RATHER THAN THE JSON ONE
//

#ifndef Dictionary_h
#define Dictionary_h

#include "../Trees/BinarySearchTree.h"
#include "../Lists/LinkedList.h"
#include "Entry.h"

struct Dictionary
{
    struct BinarySearchTree binary_search_tree;
    struct LinkedList keys;
    
    void (*insert)(struct Dictionary *dictionary, void *key, unsigned long key_size, void *value, unsigned long value_size);
    void * (*search)(struct Dictionary *dictionary, void *key, unsigned long key_size);
};

struct Dictionary dictionary_constructor(int (*compare)(void *key_one, void *key_two));
void dictionary_destructor(struct Dictionary *dictionary);

int compare_string_keys(void *entry_one, void *entry_two);

#endif /* Dictionary_h */