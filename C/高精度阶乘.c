
#include <stdio.h>
#define N 200
int c[N]= {1};
int jiechen(int n);
int main()
{
    int n;
    scanf("%d", &n);
    int i, m= n;
    for (i= 0; n; i++) {
        c[i]= n % 10;
        n/= 10;
    }
    jiechen(m - 1);
    for (i= N - 1; i > -1;) {
        if (c[--i]) break;
    }
    for (; i > -1; i--) { printf("%d", c[i]); }
    return 0;
}
int jechen(int n)
{
    if (n == 0 || n == 1) {
        return 0;
    } else {
        int i, I, J, j, m, a[N]= {0}, b[N]= {0};
        m= n - 1;
        for (i= 0; n;
             i++) {        //! 注意此处条件不可为 n%10 ,万一是600 呢？？！！！
            a[i]= n % 10;
            n/= 10;
        }
        for (i= N; i > -1;)
            if (c[--i]) break;
        for (j= N; j > -1;)
            if (a[--j]) break;
        I= i;
        J= j;
        for (j= 0; j <= J; j++) {
            for (i= 0; i <= I; i++) b[j + i]+= c[i] * a[j];
        }
        for (i= 0; i < N; i++) c[i]= b[i];
        for (i= 0; i < 200; i++) {
            if (c[i] / 10 > 0) {
                /* c[i+3]+=c[i]/1000;
                   c[i+4]+=c[i]/10000;
                   c[i+5]+=c[i]/100000;
                           c[i+2]+=c[i]/100;    */
                c[i + 1]+= c[i] / 10;
                c[i]= c[i] % 10;
            }
        }
        return jiechen(m);
    }
}