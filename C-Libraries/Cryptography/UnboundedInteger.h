//
//  UnboundedInteger.h        
//  C-Libraries/Cryptography
//
//  Created by Federico Balistreri on 8/21/24
//

#ifndef UnboundedInteger_h
#define UnboundedInteger_h

#include <stdlib.h>
#include <stdint.h>

struct UnboundedInteger
{
    uint64_t *integer;
    short sign;
    int size;   
    char *hex;  //for visualizing the whole number
};

struct UnboundedInteger unbounded_integer_constructor(short sign, int size, ...);
void unbounded_integer_destructor(struct UnboundedInteger *bignum);

#endif /* UnboundedInteger_h */