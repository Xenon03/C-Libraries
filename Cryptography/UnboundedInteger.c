//
//  UnboundedInteger.c      
//  C-Libraries/Cryptography
//
//  Created by Federico Balistreri on 8/21/24
//

#include "UnboundedInteger.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

struct UnboundedInteger unbounded_integer_constructor(short sign, int size, ...)
{
    struct UnboundedInteger number;
    number.integer = malloc(sizeof(uint64_t) * size);
    va_list blocks;
    va_start(blocks, size);
    for (int i=0; i<size; i++)
    {
        number.integer[i] = va_arg(blocks,uint64_t);
    }
    va_end(blocks);

    number.sign = sign;
    number.size = size;
    number.hex = malloc((size * 16 + 1) * sizeof(char));
    for (int i=0; i<size; i++)
    {
        char x[17];
        snprintf(x, sizeof(x), "%016lx", number.integer[i]); //sprintf(x, "%lx", number.integer[i]) works too but with 0x0001 we risk to lose leading zeros
        strcat(number.hex, x);
    }
    return number;
}

void unbounded_integer_destructor(struct UnboundedInteger *bignum)
{
    if (bignum)
    {
        free(bignum->integer);
        free(bignum->hex);
        bignum->integer = NULL;
        bignum->hex = NULL;
    }
}