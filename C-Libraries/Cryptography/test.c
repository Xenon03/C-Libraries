

#include "UnboundedInteger.h"
#include <stdio.h>
int main()
{
    struct UnboundedInteger x = unbounded_integer_constructor(0, 4, 0xB95385C2E1A23D2B, 0x1EB6A03D88164FA2, 0x4CAD86A8531EBD96, 0x7AACDF451EC2F1EB);

    printf("%s\n", x.hex);
}