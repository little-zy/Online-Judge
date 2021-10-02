
//#include <cstdlib>
#include <iostream>
//#include <stdexcept>
using namespace std;
int add()
{
    int a, b;
    cin >> a >> b;
    if (a + b > 999)
        throw "overflow";
    else if (a + b < -999)
        throw "underflow";
    else
        return a + b;
}
int main()
{
    try {
        cout << add();
    }
    catch (char const* b) {
        cout << b;
    }
    catch (...) {
        ;
    }
}