#include <stdio.h>
void main()
{
    int n, fb(int n);
    scanf("%d", &n);
    printf("%d", fb(n));
}
int fb(int n)
{
    return n == 1 || n == 2 ? 1 : fb(n - 1) + fb(n - 2);
}