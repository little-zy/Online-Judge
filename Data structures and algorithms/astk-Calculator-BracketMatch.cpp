#include <iostream>
#include <string>
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
    // int _size=0;
    alt()
    {
        Head= nullptr;
        Next= nullptr;
        //_size= 1;
    }
    alt(Object object)
    {
        /*this->*/ push_back(object);
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
        if (Iter < /*this->*/ size()) {
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
template <class Object>
class astk : public alt<Object>
{
 public:
    void push(Object object)
    {
        this->/* alt<Object>:: */push_back(object);
    }
    Object pop_out()
    {
        Object last;
        if (this->/* alt<Object>:: */size() > 0) {
            last= (*this)[this->/* alt<Object>:: */size() - 1];
            this->/* alt<Object>:: */del(this->/* alt<Object>:: */size() - 1);
        }
        return last;
    }
    Object pop_item()
    {
        Object last;
        if (this->/* alt<Object>:: */size() > 0) {
            last= (*this)[this->/* alt<Object>:: */size() - 1];
        }
        return last;
    }
    // Object &operator[](int Iter)
    // {
    // 	return this->/* alt<Object>:: */operator[](Iter);
    // }
    // int size()
    // {
    // 	return this->/* alt<Object>:: */size();
    // }
};
template <class Object>
class aque : public alt<Object>
{
 public:
    void push(Object object)
    {
        this->/* alt<Object>:: */push_back(object);
    }
    Object pop_out()
    {
        Object first;
        if (this->/* alt<Object>:: */size() > 0) {
            first= (*this)[0];
            this->/* alt<Object>:: */del(0);
        }
        return first;
    }
    Object pop_item()
    {
        Object first;
        if (this->/* alt<Object>:: */size() > 0) { first= (*this)[0]; }
        return first;
    }
    // Object &operator[](int Iter)
    // {
    // 	return this->/* alt<Object>:: */operator[](Iter);
    // }
    // int size()
    // {
    // 	return this->/* alt<Object>:: */size();
    // }
};
int main()
{
    string s;
    astk<char> m;
    getline(cin, s);
    bool tf= 1;
    for (int i= 0; i < s.length(); i++) {
        // cout << s[i];
        switch (s[i]) {
            case '{':
            case '[':
            case '(': m.push(s[i]); break;
            case ')':
                if ('(' == m.pop_out())
                    break;
                else
                    tf= 0;
            case ']':
                if ('[' == m.pop_out())
                    break;
                else
                    tf= 0;
            case '}':
                if ('{' == m.pop_out())
                    break;
                else
                    tf= 0;
            default: break;
        }
    }
    if (m.size()) tf= 0;
    string nibolan;
    astk<int> num;        //!'.'
    for (int i= 0; i < s.length(); i++) {
        // cout << s[i];
        int j= 0, tmp= 0;
        switch (s[i]) {
            case '{':
            case '[':
            case '(': m.push(s[i]); break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                j= i;
                while (s[j] <= '9' && s[j] >= '0') { j++; }
                tmp= 0;        //!'.'
                while (i < j) {
                    tmp*= 10;
                    tmp+= s[i] - '0';
                    nibolan+= s[i];
                    i++;
                }
                nibolan+= ' ';
                i--;
                num.push(tmp);
                break;
            case ')':
            case ']':
            case '}':
                while (m.pop_item() != '(') { nibolan+= m.pop_out(); }
                m.pop_out();
                break;
            case '+':
            case '-':
                while (m.pop_item() == '*' || m.pop_item() == '/') {
                    nibolan+= m.pop_out();
                }
            case '*':
            case '/': m.push(s[i]); break;
            case '.':        //!
            default: break;
        }
    }
    while (m.size() > 0) { nibolan+= m.pop_out(); }
    // cout << nibolan << endl;
    // num.print_all();
    while (num.size() > 0) { num.pop_out(); }
    for (int i= 0; i < nibolan.length(); i++) {
        // cout << s[i];
        int j= 0, tmp= 0, n1= 0, n2= 0;
        switch (nibolan[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                j= i;
                while (nibolan[j] <= '9' && nibolan[j] >= '0') { j++; }
                tmp= 0;        //!'.'
                while (i < j) {
                    tmp*= 10;
                    tmp+= nibolan[i] - '0';
                    i++;
                }
                i--;
                num.push(tmp);
                break;
            case '+':
                n1= num.pop_out(), n2= num.pop_out();
                num.push(n2 + n1);
                break;
            case '-':
                n1= num.pop_out(), n2= num.pop_out();
                num.push(n2 - n1);
                break;
            case '*':
                n1= num.pop_out(), n2= num.pop_out();
                num.push(n2 * n1);
                break;
            case '/':
                n1= num.pop_out(), n2= num.pop_out();
                num.push(n2 / n1);
                break;
            case '.':        //!
            default: break;
        }
    }
    cout << num.pop_out();
    return 0;
}