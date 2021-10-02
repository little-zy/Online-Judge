
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a;
    char s;
    while (cin >> s >> b) {
        if (s == '+') {
            a+= b;
        } else if (s == '-') {
            a-= b;
        } else {
            break;
        }
    }
    cout << a;
    return 0;
}