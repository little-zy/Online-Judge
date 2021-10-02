
#include <stdio.h>
long Mode(long a, long b, long mode);
int main()
{
    long int a, b, mode;
    puts("e");
    scanf("%d %d %d", &a, &b, &mode);
    int s;
    s= Mode(a, b, mode);
    printf("%d", s);
    return 0;
}
long Mode(long a, long b, long mode)
{
    long long sum= 1;
    while (b) {
        if (b & 1) {
            sum= (sum * a) % mode;
            b--;
        }
        b/= 2;
        a= a * a % mode;
    }
    return sum;
}