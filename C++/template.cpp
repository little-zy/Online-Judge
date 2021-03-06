
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
class SortableArray
{
 private:
    vector<T> array;
    int maxSize;
 public:
    SortableArray(int size);
    void pushBack(T t);
    void sort(void);
    void printArray(void);
};
template <typename T>
SortableArray<T>::SortableArray(int size)
{
    maxSize= size;
    vector<T> temparray;
    array= temparray;
}
template <typename T>
void SortableArray<T>::pushBack(T t)
{
    if (array.size() == maxSize) maxSize++;
    array.push_back(t);
};
template <typename T>
void SortableArray<T>::sort()
{
    for (int i= 0; i < array.size(); i++)
        for (int j= 0; j < array.size() - 1 - i; j++)
            if (array[j] > array[j + 1]) {
                T t= array[j];
                array[j]= array[j + 1];
                array[j + 1]= t;
            }
}
template <typename T>
void SortableArray<T>::printArray()
{
    for (int i= 0; i < maxSize; i++) { cout << array[i] << ' '; }
    cout << endl;
}
int main()
{
    int size= 50;
    int a[50]= {41,  467, 334, 500, 169, 724, 478, 358, 962, 464, 705, 145, 281,
                827, 961, 491, 995, 942, 827, 436, 391, 604, 902, 153, 292, 382,
                421, 716, 718, 895, 447, 726, 771, 538, 869, 912, 667, 299, 35,
                894, 703, 811, 322, 333, 673, 664, 141, 711, 253, 868};
    double b[50]= {0.00125126, 0.563585,  0.193304, 0.80874,    0.585009,
                   0.479873,   0.350291,  0.895962, 0.82284,    0.746605,
                   0.174108,   0.858943,  0.710501, 0.513535,   0.303995,
                   0.0149846,  0.0914029, 0.364452, 0.147313,   0.165899,
                   0.988525,   0.445692,  0.119083, 0.00466933, 0.0089114,
                   0.37788,    0.531663,  0.571184, 0.601764,   0.607166,
                   0.166234,   0.663045,  0.450789, 0.352123,   0.0570391,
                   0.607685,   0.783319,  0.802606, 0.519883,   0.30195,
                   0.875973,   0.726676,  0.955901, 0.925718,   0.539354,
                   0.142338,   0.462081,  0.235328, 0.862239,   0.209601};
    string s[50]= {
        "yngxwcjd",  "asdfewr",  "n",         "hafnwtkg",  "tut",
        "fnkiocrx",  "b",        "fsvqwt",    "kqawfklsa", "sofhq",
        "yjwmqrcjp", "jrpqq",    "emeovaky",  "cui",       "loaf",
        "yvtya",     "f",        "tiowrdext", "axa",       "ihhpabpbh",
        "nqkmkxin",  "xuiiito",  "asdfewr",   "aukxh",     "q",
        "xbrireb",   "fpb",      "uvlivuxg",  "ywalgty",   "lu",
        "nxkomynh",  "kmpkk",    "blauagqlk", "jxyiav",    "tkheyco",
        "slpnkl",    "x",        "nypxeqxl",  "lfsi",      "vi",
        "lamldqflc", "panj",     "dlklcnvu",  "ht",        "vqwwllhw",
        "xgrcv",     "oyryeoej", "fisoo",     "mujhx",     "asdfewr"};
    /* int array */
    SortableArray<int> intArr(size);
    for (int i= 0; i < size; i++) { intArr.pushBack(a[i]); }
    intArr.sort();
    intArr.printArray();
    /* double array */
    SortableArray<double> doubleArr(size);
    for (int i= 0; i < size; i++) { doubleArr.pushBack(b[i]); }
    doubleArr.sort();
    doubleArr.printArray();
    /* string array */
    SortableArray<string> strArr(size);
    for (int i= 0; i < size; i++) { strArr.pushBack(s[i]); }
    strArr.sort();
    strArr.printArray();
    return 0;
}