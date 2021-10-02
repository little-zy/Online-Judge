#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[10][100], c, out[10];
    int i= 0, j= 0, g= 0;
    for (i= 0; i < 10; i++) {
        if (c != '\n') {
            scanf("%s", &a[i]);
            g= i;
        } else {
            continue;
        }
        c= getchar();
    }
    g++;
    strcpy(out, a[0]);
    for (; j < g; j++) {
        if (strlen(out) < strlen(a[j])) strcpy(out, a[j]);
    }
    printf("%s", out);
    return 0;
}