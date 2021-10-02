
#include <cstdarg>
#include <iostream>
using namespace std;
class lei
{
 public:
    // int operator!(int n);
};
int main()
{
    int m, n;
    char c= 'c';
    // cin >> n;
    n= 5;
    memset(&m, 32, 40);
    char* const cp= &c;        //!常指针
    const char* pc= &c;        //!常字符
    return 0;
}
template <typename T>
int f(T arg, ...)
{
    va_list ap;
    va_start(ap, arg);
    int i, n;
    for (i= 0; i < n; i++) {
        // 根据arg 依次解释
        TT p= va_arg(ap, TT);
    }
    va_end(arg);
}
//引用返回的应为static类型
// main 函数之前的全局变量将先于main 函数的执行被赋值；