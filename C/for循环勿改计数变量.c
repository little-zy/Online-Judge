//水仙花数
#include <stdio.h>
#include <stdlib.h>  // for C
int sancifang(int a);
int main()
{
    int i, g, s, b, j;
    //                                                 for
    //                                                 循环中不能把计数变量改了
    for (i= 124; i <= 999; i++) {
        j= i;
        g= j % 10;
        j/= 10;
        s= j % 10;
        j/= 10;
        b= j % 10;
        g= sancifang(g);
        s= sancifang(s);
        b= sancifang(b);
        if (i == g + s + b) {
            printf("%d is that\n", i);
            // break;
        }
    }
    return 0;
}
int sancifang(int a)
{
    a= a * a * a;
    return a;
}