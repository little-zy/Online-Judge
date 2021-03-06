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
#define notfindsymbol -1
 protected:
    Object Data;
    alt* Next;
    alt* Head;
 public:
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
        return notfindsymbol;
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
            Object iTemp= (*this)[i]; /*???????????????*/
            int iPos= i - 1;
            while ((iPos >= 0) && (iTemp < (*this)[iPos])) /*????????????????????????*/
            {
                (*this)[iPos + 1]= (*this)[iPos]; /*????????????*/
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
        clear();
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
#define nonenodesymbol -1
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
    bitr(bitr& b)
    {
        Root= copytree(b.Root);
    }
    Node* copytree(Node* root)
    {
        Node* newroot= nullptr;
        if (root != nullptr) {
            newroot= new Node;
            newroot->data= root->data;
            if (root->left != nullptr) { newroot->left= copytree(root->left); }
            if (root->right != nullptr) {
                newroot->right= copytree(root->right);
            }
        }
        return newroot;
    }
    bitr(Object object)
    {
        if (object != nonenodesymbol) {
            Root->left= nullptr;
            Root->right= nullptr;
            Root->data= object;
        } else {
            Root= nullptr;
        }
    }
    Node* newleftnode(Node* node, Object object)
    {
        node->left= new Node(object);
        return node->left;
    }
    Node* newrightnode(Node* node, Object object)
    {
        node->right= new Node(object);
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
    int getdepth()
    {
        return depth(this->Root);
    }
    void creatBinaryTreebyLayer(Node* root)
    {
        if (root != nullptr) {
            aque<Node*> que(root);
            Object leftdata, rightdata;
            while (que.size()) {
                root= que.pop_out();
                cin >> leftdata >> rightdata;
                if (leftdata != nonenodesymbol) {
                    root->left= newleftnode(root, leftdata);
                    que.push(root->left);
                }
                if (rightdata != nonenodesymbol) {
                    root->right= newrightnode(root, rightdata);
                    que.push(root->right);
                }
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
    /*
     * returns element's node counted by layer
     *
     * static data may make it more fast when Iter increases
     * 
     * 
     */
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
        if (Root != nullptr) {
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
        } else {
            size= 0;
        }
        return size;
    }
    int layerwayfind(Object object)
    {
        int iter= 1, size= this->size();
        for (iter= 1; iter < size; iter++) {
            if ((*this)[iter] == object) return iter;
        }
        return notfindsymbol;
    }
    Object& preorder_mine(int Iter)
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
            if (stk.size()) {
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
    bitr<int> Btr1(rootdata);
    Btr1.creatBinaryTreebyLayer(Btr1.Root);
    cout << Btr1.getdepth() << ' ' << Btr1.size() << endl;
    cin >> rootdata;
    bitr<int> Btr2(rootdata);
    Btr2.creatBinaryTreebyLayer(Btr2.Root);
    cout << Btr2.getdepth() << ' ' << Btr2.size() << endl;
    cin >> rootdata;
    bitr<int> Btr(rootdata);
    Btr.Root->left= Btr.copytree(Btr1.Root);
    Btr.Root->right= Btr.copytree(Btr2.Root);
    cout << Btr.getdepth() << ' ' << Btr.size() << endl;
    int m= 0, n= Btr.size(), i= 0;
    for (i= 1; i <= n; i++) {
        m= Btr.preorder_mine(i);
        cout << m << " ";
    }
    cout << endl;
    alt<int> path;
    Btr.inorderTraversalpair(Btr.Root, path);
    for (i= 0; i < n; i++) { cout << path[i] << ' '; }
    cout << endl;
    path.clear();
    Btr.postorderTraversalpair(Btr.Root, path);
    for (i= 0; i < n; i++) { cout << path[i] << ' '; }
    return 0;
}