
#include <iostream>
using namespace std;
#include <string>
#include <vector>
vector<string> split(string str)
{
    vector<string> m;
    while (str.length()) {
        if (str.find_first_not_of(' ') <= str.find(' '))
            m.push_back(str.substr(str.find_first_not_of(' '), str.find(' ')));
        str.erase(0, str.find(' ')+1);
    }
    return m;
}
int main()
{
    /* vector<int> a= {1, 2, 3, 4, 5, 6}, b= {2, 4, 1, 6, 8, 10};
    vector<int> c= intersection(a, b);
    for (auto e : c) { cout << e << endl; } */
    string str= "hello world abc  ";
    vector<string> m= split(str);
    for (auto e : m) { cout << e << endl; }
    return 0;
}
