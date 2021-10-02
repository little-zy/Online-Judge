#include <string>
#include <iostream>
using namespace std;
struct Pair
{
    string word;
    int count= 1;
};
#define n 100
int main()
{
    Pair num[n];
    int i= 0, j= 0;
    string word;
    while (cin >> word) {
        bool tf= true;
        for (i= 0; i < j; i++) {
            if (word == num[i].word) {
                num[i].count++;
                tf= false;
            }
        }
        if (tf) num[j++].word= word;
    }
    for (i= 0; i < j; i++) {
        for (int k= j - 1; k > i; k--) {
            if (num[k].word.compare(num[k - 1].word) < 0) {
                Pair iTemp= num[k - 1];
                num[k - 1]= num[k];
                num[k]= iTemp;
            }
        }
    }
    for (int k= 0; k < j; k++) {
        cout << num[k].word << " " << num[k].count << endl;
    }
    return 0;
}