
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct Pair
{
    string word;
    vector<int> rows;
};
bool com(Pair a, Pair b)
{
    return a.word < b.word;
}
int main()
{
    Pair mm[100];
    int m= 0, n= 0;
    for (int i= 1; ! cin.eof(); i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (getline(ss, tmp, ' ')) {
            if (tmp.size() != 0) {
                for (int j= 0; j < m; j++) {
                    if (tmp == mm[j].word) {
                        mm[j].rows.push_back(i);
                        n= 1;
                        break;
                    }
                }
                if (n == 0) {
                    m++;
                    mm[m - 1].word= tmp;
                    mm[m - 1].rows.push_back(i);
                } else
                    n= 0;
            }
        }
    }
    sort(mm, mm + m, com);
    for (int i= 0; i < m; i++) {
        cout << mm[i].word;
        for (int j= 0; j < mm[i].rows.size(); j++) cout << ' ' << mm[i].rows[j];
        cout << ' ' << endl;
    }
    return 0;
}