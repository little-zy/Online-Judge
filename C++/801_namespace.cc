
#include <iostream>
namespace test {
void print(std::string s)
{
    std::cout << s;
}
int add(int a, int b)
{
    return a + b;
}
}        // namespace test
// using namespace std;
int main()
{
    std::string s= "wer";
    int a= 2, b= 3;
    test::print(s);
    int c= test::add(a, b);
    std::cout << std::endl << c << std::endl;
    return 0;
}