//
//  Entry.h
//  DataStructures
//
//  Created by Federico Balistreri on 8/19/24
//  

#ifndef Entry_h
#define Entry_h

struct Entry 
{
    void *key;
    void *value;
};

struct Entry entry_constructor(void *key, unsigned long key_size, void *value, unsigned long value_size);
void entry_destructor(struct Entry *entry);

#endif /* Entry_h */