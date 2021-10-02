#include <iostream>
using namespace std;
template <class Object>
class alt
/*
 *
 * alt is the short of Array-Linked-list
 *
 * which is using linked list to realize arrays
 *
 * template form makes it convenient to be widely used
 *
 * any questions please contact zy
 *
 * All rights reserved
 *
 * 2021
 *
 */
{
    Object Data;
    alt* Next= nullptr;
    alt* Head= nullptr;
    // int _size=0;
 public:
    alt()
    {
        Head= nullptr;
        Next= nullptr;
        //_size= 1;
    }
    alt(Object object)
    {
        this->push_back(object);
        Head= this;
    }
    void push_back(Object object)
    {
        alt* next= Head;
        if (next != nullptr) {
            while (next->Next != nullptr) { next= next->Next; }
            next->Next= new alt;
            next= next->Next;
            next->Head= Head;
        } else {
            Head= this;
            next= Head;
        }
        next->Data= object;
        // next->Next= nullptr;
        //_size++;
    }
    Object& operator[](int Iter)
    {
        alt* next= Head;
        while (Iter-- && next != nullptr) { next= next->Next; }
        return next->Data;
    }
    int size()
    {
        if (Head == nullptr) return 0;
        int cnt= 1;
        alt* next= Head;
        while (next->Next != nullptr) {
            next= next->Next;
            cnt++;
        }
        return cnt;
    }
    int find(Object object)
    {
        int cnt= this->size();
        int Iter= 0;
        alt* next= Head;
        while (cnt--) {
            if (next->Data == object) return Iter;
            Iter++;
            next= next->Next;
        }
        return -1;
    }
    void del(int Iter)
    {
        int cnt= this->size();
        if (Iter >= cnt)
            return;
        else {
            alt* next= Head;
            alt* front= next;
            while (Iter--) {
                front= next;
                next= next->Next;
            }
            front->Next= next->Next;
            if (next == Head) {
                Head= next->Next;
                while (next->Next != nullptr) {
                    next->Head= Head;
                    next= next->Next;
                }
                // this=Head;
            }
            // delete next;
            return;
        }
    }
    void del_item(Object object)
    {
        del(this->find(object));
    }
    void Sort()
    {
        int cnt= this->size();
        for (int i= 1; i < cnt; i++) /*循环数组中元素*/
        {
            Object iTemp= (*this)[i]; /*设置插入值*/
            int iPos= i - 1;
            while ((iPos >= 0) && (iTemp < (*this)[iPos])) /*寻找插入值的位置*/
            {
                (*this)[iPos + 1]= (*this)[iPos]; /*插入数值*/
                iPos--;
            }
            (*this)[iPos + 1]= iTemp;
        }
    }
    void print_all()
    {
        int i= 0, cnt= this->size();
        for (i= 0; i < cnt - 1; i++) { cout << (*this)[i] << ' '; }
        if (cnt == 0)
            cout << endl;
        else
            cout << (*this)[i] << endl;
    }
    ~alt()
    {
        ;
    }
};
int yuesefu(int sum, int value, int n)
{
    if (n == 1)
        return (value - 1) % sum;
    else
        return (yuesefu(sum - 1, value, n - 1) + value) % sum;
}
int main()
{
    string dtype;
    cin >> dtype;
    if (dtype == "int") {
        alt<int> M;
        int item;
        int n= 0, x= 0, y= 0;
        cin >> n;
        int n1= n;
        while (n--) {
            cin >> item;
            M.push_back(item);
        }
        M.print_all();
        cin >> x >> y;
        // cin >> y;
        int j0= 0, i= 0;
        alt<int> list;
        for (i= 0; i < y; i++) {
            j0= yuesefu(n1, x, i + 1);
            list.push_back(j0);
            cout << M[j0] << endl;
            // M.del(j0);
        }
        j0++;
        list.Sort();
        for (i= list.size() - 1; i >= 0; i--) {
            M.del(list[i]);
            if (j0 > list[i]) j0--;
        }
        if (M.size() > 0) {
            for (i= 0; i < M.size() - 1; i++) {
                cout << M[(j0 + i) % M.size()] << ' ';
            }
            cout << M[(j0 + i) % M.size()] << endl;
        }
    }
    if (dtype == "float") {
        alt<float> M;
        float item;        //
        int n= 0, x= 0, y= 0;
        cin >> n;
        int n1= n;
        while (n--) {
            cin >> item;
            M.push_back(item);
        }
        M.print_all();
        cin >> x >> y;
        // cin >> y;
        int j0= 0, i= 0;
        alt<int> list;
        for (i= 0; i < y; i++) {
            j0= yuesefu(n1, x, i + 1);
            list.push_back(j0);
            cout << M[j0] << endl;
            // M.del(j0);
        }
        j0++;
        list.Sort();
        for (i= list.size() - 1; i >= 0; i--) {
            M.del(list[i]);
            if (j0 > list[i]) j0--;
        }
        if (M.size() > 0) {
            for (i= 0; i < M.size() - 1; i++) {
                cout << M[(j0 + i) % M.size()] << ' ';
            }
            cout << M[(j0 + i) % M.size()] << endl;
        }        //
    }
    if (dtype == "char") {
        alt<char> M;
        char item;        //
        int n= 0, x= 0, y= 0;
        cin >> n;
        int n1= n;
        while (n--) {
            cin >> item;
            M.push_back(item);
        }
        M.print_all();
        scanf("%d %d", &x, &y);
        // cin >> y;
        int j0= 0, i= 0;
        alt<int> list;
        for (i= 0; i < y; i++) {
            j0= yuesefu(n1, x, i + 1);
            list.push_back(j0);
            cout << M[j0] << endl;
            // M.del(j0);
        }
        j0++;
        list.Sort();
        for (i= list.size() - 1; i >= 0; i--) {
            M.del(list[i]);
            if (j0 > list[i]) j0--;
        }
        if (M.size() > 0) {
            for (i= 0; i < M.size() - 1; i++) {
                cout << M[(j0 + i) % M.size()] << ' ';
            }
            cout << M[(j0 + i) % M.size()] << endl;        //! size==0
        }
    }
    return 0;
}
