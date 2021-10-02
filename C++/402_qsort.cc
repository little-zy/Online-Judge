
#include <iostream>
using namespace std;
struct Point
{
    float x;
    float y;
};
int cmp(const void* a, const void* b)
{
    Point* a1= (Point*)a;
    Point* b1= (Point*)b;
    float res= (a1->x) * (a1->x) + (a1->y) * (a1->y) - (b1->x) * (b1->x) -
        (b1->y) * (b1->y);
    if (res == 0) {
        float x= a1->x - b1->x;
        if (x == 0) {
            float y= a1->y - b1->y;
            return y;
        } else
            return x;
    } else
        return res;
}
int main()
{
    int n;
    cin >> n;
    Point num[n];
    for (int i= 0; i < n; i++) { cin >> num[i].x >> num[i].y; }
    // cout<<endl;
    qsort(num, n, sizeof(num[0]), &cmp);
    for (int i= 0; i < n; i++) { cout << num[i].x << " " << num[i].y << endl; }
    return 0;
}