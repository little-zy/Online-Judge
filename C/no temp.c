
#include <stdio.h>
int main()
{
    int a= 20, b= 55;
    a+= b;
    b= a - b;
    a= a - b;
    printf("a=%d,b=%d\n", a, b);
    a^= b;
    b^= a;
    a^= b;
    printf("a=%d,b=%d\n", a, b);
    char ch= 'A';
    ch^= 32;
    printf("%c\n", ch);
    return 0;
}