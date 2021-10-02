#include <stdio.h>
#define IBM_PC
int main()
{
    int x= -1;
    x= x | 0377;
    printf("%d,%x\n", x, x);
    return 0;
}