
#include <iostream>
#include <string>
using namespace std;
struct num
{
    string a;
    int b;
};
int num_cmp(const void* x, const void* y)
{
    num* a= (num*)x;
    num* b= (num*)y;
    return (a->a) > (b->a) ? 1 : -1;
}
int main()
{
    string dat1;
    num tmp[600];
    num* p[600]= {0};
    int cnt1= 0;
    static int a= 0;
    while (cin >> dat1) {
        if (dat1 == "end") break;
        bool is= 0;
        for (int i= 0; i < cnt1; i++) {
            if (tmp[i].a == dat1) {
                tmp[i].b++;
                is= 1;
                break;
            }
        }
        if (! is) {
            p[cnt1]= &tmp[cnt1];
            tmp[cnt1].a= dat1;
            tmp[cnt1].b= 1;
            cnt1++;
        }
    }
    // qsort(p[0], cnt1, sizeof(tmp[0]), num_cmp);
    bool is= 1;
    while (is) {
        is= 0;
        for (int i= 0; i < cnt1 - 1; i++) {
            if (num_cmp(p[i], p[i + 1]) == 1) {
                num* tmp= p[i];
                p[i]= p[i + 1];
                p[i + 1]= tmp;
                is= 1;
            }
        }
    }
    for (int i= 0; i < cnt1; i++) { cout << p[i]->a << " " << p[i]->b << endl; }
}