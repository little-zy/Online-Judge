#include <iostream>
using namespace std;
class NDvector
{
 public:
    NDvector();
    NDvector(int n, int arr[]);
    NDvector(const NDvector& other);
    ~NDvector();
    NDvector operator+(const NDvector& other) const;
    NDvector operator-(const NDvector& other) const;
    int operator*(const NDvector& other) const;
    NDvector& operator=(const NDvector& other);
    bool operator==(const NDvector& other) const;
    friend ostream& operator<<(ostream& o, const NDvector& v);

 private:
    int dim;
    int* data;
};
NDvector::NDvector()
{
    dim= 0;
}
NDvector::NDvector(int n, int arr[])
//!
//?
// todo
{
    dim= n;
    //int newarr[n];        //?第二次调用的时候把第一次的覆盖了
                          //?而且调用结束之后内存空间也没了
    int* newarr=new int[n];
    for (int i= 0; i < n; i++) { newarr[i]= arr[i]; }
    data= newarr;
    // *data=arr[0];
    // for (int i= 0; i < n; i++) { data[i]= arr[i]; }
}
NDvector::NDvector(const NDvector& other) : dim(other.dim)
{        //不能用data(other.data)
    int* newarr=new int[dim];
    for (int i= 0; i < dim; i++) { newarr[i]= other.data[i]; }
    data= newarr;
    // for (int i= 0; i < dim; i++) { data[i]= other.data[i]; }
}
NDvector::~NDvector()
{
    // delete dim;
    // delete dat;a
}
NDvector NDvector::operator+(const NDvector& other) const
{
    NDvector a= NDvector(*this);
    for (int i= 0; i < dim; i++) { a.data[i]+= other.data[i]; }
    return a;
}
NDvector NDvector::operator-(const NDvector& other) const
{
    NDvector a= NDvector(*this);
    for (int i= 0; i < dim; i++) { a.data[i]-= other.data[i]; }
    return a;
}
int NDvector::operator*(const NDvector& other) const
{
    int a= 0;
    for (int i= 0; i < dim; i++) { a+= this->data[i] * other.data[i]; }
    return a;
}
NDvector& NDvector::operator=(const NDvector& other)
{
    if (this != &other) {
        this->dim= other.dim;
        this->data= other.data;
    }
    return *this;
}
bool NDvector::operator==(const NDvector& other) const
{
    for (int i= 0; i < dim; i++) {
        if (this->data[i] != other.data[i]) return false;
    }
    return true;
}
ostream& operator<<(ostream& out, const NDvector& v)
{
    out << "(";
    int i= 0;
    for (; i < v.dim - 1; i++) { out << v.data[i] << ","; }
    out << v.data[i] << ")";
    return out;
}
int main()
{
    int m;
    cin >> m;
    int* v1= new int[m];
    int* v2= new int[m];
    for (int i= 0; i < m; i++) cin >> v1[i];
    for (int i= 0; i < m; i++) cin >> v2[i];
    NDvector vec_1(m, v1);
    NDvector vec_2(m, v2);
    delete[] v1;
    delete[] v2;
    NDvector vec_3= vec_1 + vec_2;
    NDvector vec_4= vec_1 - vec_2;
    int product= vec_1 * vec_2;
    bool equal= vec_1 == vec_2;
    cout << vec_3 << endl;
    cout << vec_4 << endl;
    cout << product << endl;
    cout << equal << endl;
}
