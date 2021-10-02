
#include <iostream>
using namespace std;
template <typename ElementType>
class Queue
{
 public:
    Queue();
    Queue(const Queue<ElementType>& Queue);
    ~Queue();
    bool empty() const;
    size_t size() const;
    ElementType top() const;
    void push(ElementType ele);
    void pop();
 private:
    struct Node
    {
        ElementType element;
        Node* next;
        Node(ElementType ele, Node* next= NULL) : element(ele), next(next){};
    };
    Node* front;
    Node* back;
    size_t _size;
};
int main()
{
    Queue<string> q0;
    if (q0.empty()) cout << "is empty" << endl;
    q0.push("123");
    if (q0.empty())
        cout << "is empty" << endl;
    else
        cout << "not empty" << endl;
    q0.push("22");
    cout << q0.size() << endl;
    string a= q0.top();
    q0.push(a);
    cout << q0.size() << endl;
    q0.pop();
    cout << q0.size() << endl;
    q0.pop();
    cout << q0.size() << endl;
    q0.pop();
    cout << q0.size() << endl;
    q0.pop();
    cout << q0.size() << endl;
    q0.push("22");
    cout << q0.size() << endl;
    if (q0.empty())
        cout << "is empty" << endl;
    else
        cout << "not empty" << endl;
    q0.push("22");
    q0.push("22");
    q0.push("22");
    Queue<string> q1= Queue<string>(q0);
    if (q1.empty()) cout << "is empty" << endl;
    q1.push("123");
    if (q1.empty())
        cout << "is empty" << endl;
    else
        cout << "not empty" << endl;
    q1.push("22");
    cout << q1.size() << endl;
    q1.push(a);
    cout << q1.size() << endl;
    q1.pop();
    cout << q1.size() << endl;
    q1.pop();
    cout << q1.size() << endl;
    q1.pop();
    cout << q1.size() << endl;
    q1.pop();
    cout << q1.size() << endl;
    q1.push("22");
    cout << q1.size() << endl;
    if (q1.empty()) cout << "is empty" << endl;
    return 0;
}
template <typename ElementType>
Queue<ElementType>::Queue()
{
    _size= 0;
    front= back= NULL;
}
template <typename ElementType>
void Queue<ElementType>::push(ElementType ele)
{
    if (_size) {
        Node* pnext= front;
        while (pnext->next != NULL) { pnext= pnext->next; }
        // Node newdata= Node(ele);
        Node* newdata= new Node(ele);
        pnext->next= back= newdata;
        _size++;
    } else {
        Node* newdata= new Node(ele);
        _size= 1;
        back= front= newdata;
    }
}
template <typename ElementType>
ElementType Queue<ElementType>::top() const
{
    //!
    if (front == NULL)
        return NULL;
    else
        return front->element;
}
template <typename ElementType>
void Queue<ElementType>::pop()
{
    if (front == NULL)
        return;
    else if (front->next != NULL) {
        Node* temp= front;
        front= front->next;
        delete temp;
        _size--;
    } else {
        delete front;
        front= back= NULL;
        _size= 0;
    }
}
template <typename ElementType>
size_t Queue<ElementType>::size() const
{
    return _size;
}
template <typename ElementType>
bool Queue<ElementType>::empty() const
{
    if (_size == 0)
        return true;
    else
        return false;
}
template <typename ElementType>
Queue<ElementType>::Queue(const Queue<ElementType>& Q)
{
    //!
    _size= 0;
    Node* pnext= Q.front;
    while (pnext != NULL) {
        push(pnext->element);
        pnext= pnext->next;
    }
    _size= Q.size();
}
template <typename ElementType>
Queue<ElementType>::~Queue()
{
    while (front) { pop(); }
}
/*
 * @CreatDate    : 07-02-2021 18:44:08
 * @Author       : zhouy676
 * @LastEditTime : 07-02-2021 18:53:48
 * @LastEditors  : zhouy676
 * @FilePath     : \Coding\C++\Exercises\test.cpp
 * Copyright® 2021 zhouy676
 */
/* template <typename ElementType>
Queue<ElementType>::Queue()
{
    _size= 0;
}
template <typename ElementType>
void Queue<ElementType>::push(ElementType ele)
{
    Node* newdata= back= new Node(ele);
    if (_size) {
        Node* pnext= front;
        while (pnext->next != NULL) { pnext= pnext->next; }
        pnext->next= newdata;
    } else {
        front= newdata;
    }
    _size++;
}
template <typename ElementType>
ElementType Queue<ElementType>::top() const
{
    return front ? front->element : NULL;
}
template <typename ElementType>
void Queue<ElementType>::pop()
{
    if (front->next != NULL) {
        Node* temp= front;
        front= front->next;
        delete temp;
    } else {
        delete front;
        front= back= NULL;
    }
    _size--;
}
template <typename ElementType>
size_t Queue<ElementType>::size() const
{
    return _size;
}
template <typename ElementType>
bool Queue<ElementType>::empty() const
{
    return _size ? false : true;
}
template <typename ElementType>
Queue<ElementType>::Queue(const Queue<ElementType>& Q)= default;
template <typename ElementType>
Queue<ElementType>::~Queue()= default; */