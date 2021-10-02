#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double tmp, sum= 0;
    while (cin >> tmp) { sum+= tmp; }
    cout << fixed << setprecision(1) << sum;
    return 0;
}