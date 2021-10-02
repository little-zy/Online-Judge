#include <stdio.h>
int main()
{
    int i, j, n= 9;
    for (i= 0; i < n; i++) {
        for (j= 0; j < n; j++) printf("%d ", i * 9 + j);
        puts("");
    }
    return 0;
}