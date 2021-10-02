#include <stdio.h>
#include <string.h>
int main()
{
    char name[80], typed[80];
    gets(name);
    gets(typed);
    int tf= 0;
    int j, i= 0, k= 1, m= 0, n= 0;
    for (i= 0; i < strlen(name) && tf == 0; i++) {
        if (name[i] == name[i + 1]) {
            m++;
            continue;
        }
        for (j= i - m; (j + k - 1) < strlen(typed);) {
            if (typed[j + k] == name[i]) {
                k++, n++;
            } else if (n < m) {
                tf= 1;
                break;
            } else if (typed[j + k] == name[i + 1]) {
                break;
            } else {
                tf= 1;
                break;
            }
        }
        m= n= 0;
    }
    if (tf)
        puts("false");
    else
        puts("true");
    return 0;
}