
// todo 写一个去注释的程序，去html,
//todo 行李箱GPS粗略定位（高铁
// todo pdf书签排序按页码
#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct test
{
    // int f(int);
 public:
    int f(int in)
    {
        int out;
        out= 2 * in;
        return out;
    }
};
int main()
{
    stack<int> s;
    s.push(3);
    test a;
    int m;
    cin >> m;
    cout << a.f(m);
    return 0;
}