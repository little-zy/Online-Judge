#include <stdio.h>
int jwandpf(int n);
int i= 0;
int main()
{
    int n= 4;
    int fast= 0, slow= 0;
    // puts("vv");
    scanf("%d", &n);
    slow= jwandpf(n);
    fast= jwandpf(slow);
    while (fast != slow) {
        fast= jwandpf(fast);
        fast= jwandpf(fast);
        slow= jwandpf(slow);
    }
    if (fast == 1)
        puts("True");
    else
        puts("False");
    return 0;
}
int jwandpf(int n)
{
    int c= n;
    int jw= 0, result= 0, a[5]= {3};
    while (n > 0) {
        n= n / 10;
        jw++;
    }
    for (i= 0; i < jw; i++) {
        a[i]= c % 10;
        c/= 10;
        result+= a[i] * a[i];
    }
    return result;
}