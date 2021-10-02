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
 public:
    Object Data;
    alt* Next;
    alt* Head;
    alt()
    {
        Head= nullptr;
        Next= nullptr;
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
    }
    Object& operator[](int Iter)
    {
        if (Iter < this->size()) {
            alt* next= Head;
            while (Iter-- && next != nullptr) { next= next->Next; }
            return next->Data;
        }
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
        for (int i= 1; i < cnt; i++) {
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
template <class Object>
class astk : public alt<Object>
{
 public:
    void push(Object object)
    {
        this->push_back(object);
    }
    Object pop_out()
    {
        Object last;
        if (this->size() > 0) {
            last= (*this)[this->size() - 1];
            this->del(this->size() - 1);
        }
        return last;
    }
    Object pop_item()
    {
        Object last;
        if (this->size() > 0) { last= (*this)[this->size() - 1]; }
        return last;
    }
};
template <class Object>
class aque : public alt<Object>
{
 public:
    void push(Object object)
    {
        this->push_back(object);
    }
    Object pop_out()
    {
        Object first;
        if (this->size() > 0) {
            first= (*this)[0];
            this->del(0);
        }
        return first;
    }
    Object pop_item()
    {
        Object first;
        if (this->size() > 0) { first= (*this)[0]; }
        return first;
    }
};
struct customer
{
    aque<int> artime;
    aque<int> svtime;
    aque<int> quetime;
    void Sort() {}
};
int main()
{
    alt<int> waiter;
    customer cs;
    int w, c;
    cin >> w >> c;
    for (int i= 0; i < w; i++) { waiter.push_back(0); }
    for (int i= 0; i < c; i++) {
        int arrivaltime;
        cin >> arrivaltime;
        cs.artime.push(arrivaltime);
    }
    for (int i= 0; i < c; i++) {
        int servertime;
        cin >> servertime;
        cs.svtime.push(servertime);
        cs.quetime.push(-1);
    }
    int list= 0, now= 0;
    while (list < c) {
        // waiter.Sort();
        for (int i= 0; i < w; i++) {
            if (waiter[i] <= 0 && list < c && cs.artime[list] <= now) {
                waiter[i]= cs.svtime[list];
                if (list > 0 && cs.svtime[list - 1] == 0) {
                    cs.quetime[list]=
                        now - cs.artime[list] - 1 - cs.quetime[list - 1];
                } else
                    cs.quetime[list]= now - cs.artime[list];
                list++;
            }
        }
        now++;
        for (int i= 0; i < w; i++) {
            if (waiter[i] > 0) waiter[i]--;
        }
    }
    int sum= 0;
    for (int i= 0; i < c; i++) { sum+= cs.quetime[i]; }
    cout << sum / c;
    return 0;
}