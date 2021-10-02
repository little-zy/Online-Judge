
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
template <typename ElementType>
Queue<ElementType>::Queue()
{
    _size= 0;
    front=back=NULL;
}
template <typename ElementType>
void Queue<ElementType>::push(ElementType ele)
{
    if (_size) {
        Node newdata= Node(ele, front);
        front= &newdata;
        /* Node* pnext= front;
        while (pnext != NULL) {
          //!  pnext->front= front;
            pnext= pnext->next;
        } */
        _size++;
    } else {
        Node newdata= Node(ele);
        _size++;
        front= &newdata;
        back= NULL;
    }
}
template <typename ElementType>
ElementType Queue<ElementType>::top() const
{
    return front->element;
}
template <typename ElementType>
void Queue<ElementType>::pop()
{
    if (front->next != NULL) {
        Node* temp= front;
        front= front->next;
        // delete temp;
        
    }else{
        //delete front;
        front=NULL;
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
    if (_size == 0)
        return true;
    else
        return false;
}
template <typename ElementType>
Queue<ElementType>::Queue(const Queue<ElementType>& Q)
{
    Node* pnext= Q.front;
    while (pnext != NULL) {
        push(pnext->element);
        pnext= pnext->next;
    }
    _size=Q.size();
}
template <typename ElementType>
Queue<ElementType>::~Queue()= default;
