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
            if (cnt == 1) {
                Head= nullptr;
                Next= nullptr;
            }
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
    void clear()
    {
        int size= this->size();
        while (size--) { this->del(size); }
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
    astk()
    {
        this->Head= nullptr;
        this->Next= nullptr;
    }
    astk(Object object)
    {
        push(object);
    }
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
    aque(Object object)
    {
        push(object);
    }
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
template <class Object>
class bitr
/*
 *
 * bitr is the short of BinaryTree
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
    struct Node
    {
        Object data;
        Node* left;
        Node* right;
        Node() : left(nullptr), right(nullptr) {}
        Node(Object object, Node* L= nullptr, Node* R= nullptr)
            : data(object), left(L), right(R)
        {}
        ~Node() {}
    };
    Node* Root= new Node;
    bitr() {}
    bitr(Object object)
    {
        Root->left= nullptr;
        Root->right= nullptr;
        Root->data= object;
    }
    Node* newleftnode(Node* node, Object object)
    {
        node->left= new Node(object);
        return node->left;
    }
    Node* newrightnode(Node* node, Object object)
    {
        node->right= new Node(object);
        // node->right->data= object;
        // node->right->left= nullptr;
        // node->right->right= nullptr;
        return node->right;
    }
    Node* leftnode(const Node* node)
    {
        return *(node->left);
    }
    Node* rightnode(const Node* node)
    {
        return *(node->right);
    }
    int depth(const Node* root) const
    {
        if (root == nullptr)
            return 0;
        else {
            int L= depth(root->left), R= depth(root->right);
            return ((L > R ? L : R)) + 1;
        }
    }
    void creatBinaryTreebyLayer(Node* root)
    {
        aque<Node*> que(root);
        Object leftdata, rightdata;
        while (que.size()) {
            root= que.pop_out();
            cin >> leftdata >> rightdata;
            if (leftdata != -1) {
                root->left= newleftnode(root, leftdata);
                que.push(root->left);
            }
            if (rightdata != -1) {
                root->right= newrightnode(root, rightdata);
                que.push(root->right);
            }
        }
        return;
    }
    Object& operator[](int Iter)
    /*
     * returns element counted by layer
     */
    {
        Node* node= this->return_node(Iter);
        return node->data;
    }
    Node* return_node(int Iter)
    {
        // if(Iter<=this->size())
        static int current= 0;
        Node* node= Root;
        static aque<Node*> que(node);
        if (Iter < current) {
            current= 0;
            que.clear();
            que.push(node);
            while (que.size() && Iter--) {
                node= que.pop_out();
                current++;
                if (node->left != nullptr) { que.push(node->left); }
                if (node->right != nullptr) { que.push(node->right); }
            }
        } else {
            Iter-= current;
            while (que.size() && Iter--) {
                node= que.pop_out();
                current++;
                if (node->left != nullptr) { que.push(node->left); }
                if (node->right != nullptr) { que.push(node->right); }
            }
        }
        return node;
    }
    int size() const
    {
        int size= 1;
        Node* node= Root;
        aque<Node*> que(node);
        while (que.size()) {
            node= que.pop_out();
            if (node->left != nullptr) {
                que.push(node->left);
                size++;
            }
            if (node->right != nullptr) {
                que.push(node->right);
                size++;
            }
        }
        return size;
    }
    int layerwayfind(Object object)
    {
        int iter= 1, size= this->size();
        for (iter= 1; iter < size; iter++) {
            if ((*this)[iter] == object) return iter;
        }
        return -1;
    }
    Object& mypreorder(int Iter)
    {
        // if(Iter<=this->size())
        int current= 1;
        Iter-= current;
        Node* Base_Node= Root;
        astk<Node*> Base_stk(Base_Node);
        bitr<int> table(1);
        Node* Table_Node= table.Root;
        astk<Node*> Table_stk(Table_Node);
        while (Iter) {
            if (Base_Node->left != nullptr && Table_Node->left == nullptr) {
                Base_Node= Base_Node->left;
                Base_stk.push(Base_Node);
                Table_Node= table.newleftnode(Table_Node, 1);
                Table_stk.push(Table_Node);
                current++;
                Iter--;
                continue;
            }
            Base_Node= Base_stk.pop_out();
            Table_Node= Table_stk.pop_out();
            if (Base_Node->right != nullptr) {
                Base_Node= Base_Node->right;
                Base_stk.push(Base_Node);
                Table_Node= table.newrightnode(Table_Node, 1);
                Table_stk.push(Table_Node);
                current++;
                Iter--;
            }
        }
        Base_Node= Base_stk.pop_item();
        return Base_Node->data;
    }
    void preorder(Node* node, alt<Object>& path)
    {
        if (node != nullptr) {
            path.push_back(node->data);
            preorder(node->left, path);
            preorder(node->right, path);
        }
    }
    /* Object& posorder(int Iter)
    {
        // if(Iter<=this->size())
        int current= 0;
        Iter-= current;
        Node* Base_Node= Root;
        astk<Node*> Base_stk(Base_Node);
        bitr<int> table(0);
        Node* Table_Node= table.Root;
        astk<Node*> Table_stk(Table_Node);
        while (Iter) {


            if (Base_Node->left != nullptr && Table_Node->left == nullptr) {
                Base_Node= Base_Node->left;
                Base_stk.push(Base_Node);
                Table_Node= table.newleftnode(Table_Node, 1);
                Table_stk.push(Table_Node);
                continue;
            } Base_Node= Base_stk.pop_item();
            Table_Node= Table_stk.pop_item();
                Base_Node= Base_Node->right;
                Base_stk.push(Base_Node);
                Table_Node= table.newrightnode(Table_Node, 1);
                Table_stk.push(Table_Node);
                current++;
                Iter--;
                // continue;
                // else if (Base_Node->right != nullptr &&
                //          Table_Node->right == nullptr)
                // {
                //     Table_Node->data= 2;
                //     current++;
                //     Iter--;
                //     continue;
                // }
                // else {}
                return Base_Node->data;
    } */
    void inorder(Node* node, alt<Object>& path)
    {
        if (node != nullptr) {
            inorder(node->left, path);
            path.push_back(node->data);
            inorder(node->right, path);
        }
    }
    void posorder(Node* node, alt<Object>& path)
    {
        if (node != nullptr) {
            posorder(node->left, path);
            posorder(node->right, path);
            path.push_back(node->data);
        }
    }
    void preorderTraversal(Node* root, alt<Object>& path)
    {
        astk<Node*> stk;
        Node* p= root;
        while (p != nullptr || stk.size()) {
            while (p != nullptr) {
                path.push_back(p->data);
                stk.push(p);
                p= p->left;
            }
            if (stk.size()) {//? 每返回上一个结点做一次向右的让步
                p= stk.pop_out();
                p= p->right;
            }
        }
    }
    void preorderTraversalnew(Node* root, alt<Object>& path)
    {
        astk<Node*> stk;
        stk.push(root);
        while (stk.size()) {
            root= stk.pop_out();
            if (root == nullptr) {
                continue;
            } else {
                path.push_back(root->data);
                stk.push(root->right);
                stk.push(root->left);
            }
        }
    }
    void inorderTraversal(Node* root, alt<Object>& path)
    {
        astk<Node*> stk;
        Node* p= root;
        while (p != nullptr || stk.size()) {
            while (p != nullptr) {
                stk.push(p);
                p= p->left;
            }
            if (stk.size()) {
                p= stk.pop_out();
                path.push_back(p->data);
                p= p->right;
            }
        }
    }
    void preorderTraversalpair(Node* root, alt<Object>& path)
    {
        astk<pair<Node*, bool>> s;
        s.push(make_pair(root, false));
        bool visited;
        while (s.size()) {
            root= s.pop_item().first;
            visited= s.pop_item().second;
            s.pop_out();
            if (root == nullptr) continue;
            if (visited)
                path.push_back(root->data);
            else {
                s.push(make_pair(root->right, false));
                s.push(make_pair(root->left, false));
                s.push(make_pair(root, true));
            }
        }
    }
    void inorderTraversalpair(Node* root, alt<Object>& path)
    {
        astk<pair<Node*, bool>> s;
        s.push(make_pair(root, false));
        bool visited;
        while (s.size()) {
            root= s.pop_item().first;
            visited= s.pop_item().second;
            s.pop_out();
            if (root == nullptr) continue;
            if (visited)
                path.push_back(root->data);
            else {
                s.push(make_pair(root->right, false));
                s.push(make_pair(root, true));
                s.push(make_pair(root->left, false));
            }
        }
    }
    void postorderTraversalpair(Node* root, alt<Object>& path)
    {
        astk<pair<Node*, bool>> s;
        s.push(make_pair(root, false));
        bool visited;
        while (s.size()) {
            root= s.pop_item().first;
            visited= s.pop_item().second;
            s.pop_out();
            if (root == nullptr) continue;
            if (visited)
                path.push_back(root->data);
            else {
                s.push(make_pair(root, true));
                s.push(make_pair(root->right, false));
                s.push(make_pair(root->left, false));
            }
        }
    }
    void clear()
    {
        ;
    }
    void delsubtree(Node* node)
    {
        // if (node->left != nullptr) delsubtree(node->left);
        // if (node->right != nullptr) delsubtree(node->right);
        // delete node;
    }
    void addtree() {}
    void Sort() {}
    void print_all() {}
    ~bitr() {}
};
int main()
{
    int rootdata;
    cin >> rootdata;
    bitr<int> Btr(rootdata);
    Btr.creatBinaryTreebyLayer(Btr.Root);
    int m= 0;
    // m= Btr[8];
    // Btr[6]= 3;
    // Btr[2]= 20;
    // m= Btr.size();
    // m= Btr.layerwayfind(20);
    // cout << endl;
    int n= Btr.size(), i= 0;
    for ( i= 1; i < n; i++) {
        m= Btr.mypreorder(i);
        cout << m << " ";
    }
    cout << Btr.mypreorder(i) << endl;
    alt<int> path;
    // Btr.preorderTraversalpair(Btr.Root, path);
    // for (i= 0; i < n - 1; i++) { cout << path[i] << ' '; }
    // cout << path[i] << endl;
    // path.clear();
    Btr.inorderTraversalpair(Btr.Root, path);
    for (i= 0; i < n - 1; i++) { cout << path[i] << ' '; }
    cout << path[i] << endl;
    path.clear();
    Btr.postorderTraversalpair(Btr.Root, path);
    for (i= 0; i < n - 1; i++) { cout << path[i] << ' '; }
    cout << path[i];
    return 0;
}