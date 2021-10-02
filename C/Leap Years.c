
#include <stdio.h>
int main()
{
    int n, y;
    scanf("%d", &n);
    int i;
    for (i= 0; i < n; i++) {
        ;
        scanf("%d", &y);
        if (y % 4 == 0) {
            if (y % 100 == 0) {
                if (y % 400 == 0) {
                    puts("True");
                } else {
                    puts("False");
                }
            } else {
                puts("True");
            }
        } else {
            puts("False");
        }
    }
    return 0;
}