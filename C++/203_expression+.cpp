
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    long long tmp= 0, total= 0;
    short flag= 1;
    cin >> str;
    for (auto c : str) {
        if (c >= '0' && c <= '9') {
            tmp*= 10;
            tmp+= c - '0';
        } else {
            total+= flag * tmp;
            tmp= 0;
            flag= c == '-' ? -1 : 1;
        }
    }
    total+= flag * tmp;
    cout << total << endl;
    return 0;
}