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
// Your code will be insert here .
NDvector::NDvector()= default;
/* NDvector::NDvector(int n, int arr[])
{
    dim= n;
    int* newarr= new int[n];
    for (int i= 0; i < n; i++) { newarr[i]= arr[i]; }
    data= newarr;
} */
NDvector::NDvector(int n, int arr[]) : dim(n)
{
    data= new int[n];
    for (int i= 0; i < n; i++) { data[i]= arr[i]; }//!不是生存期的问题，而是根本没初始化赋值
}
/* NDvector::NDvector(const NDvector& other) : dim(other.dim)
{
    int* newarr= new int[dim];
    for (int i= 0; i < dim; i++) { newarr[i]= other.data[i]; }
    data= newarr;
} */
NDvector::NDvector(const NDvector& other)
{
    NDvector(other.dim, other.data);
}
NDvector::~NDvector()
{
    delete data;
}
NDvector NDvector::operator+(const NDvector& other) const
{
    NDvector sum= NDvector(dim, other.data);
    for (int i= 0; i < dim; i++) { sum.data[i]+= data[i]; }
    return sum;
}
NDvector NDvector::operator-(const NDvector& other) const
{
    NDvector de= NDvector(dim, data);
    for (int i= 0; i < dim; i++) { de.data[i]-= other.data[i]; }
    return de;
}
int NDvector::operator*(const NDvector& other) const
{
    int x= 0;
    for (int i= 0; i < dim; i++) { x+= data[i] * other.data[i]; }
    return x;
}
NDvector& NDvector::operator=(const NDvector& other)
{
    /* if (this != &other) {
        this->dim= other.dim;
        this->data= other.data;
    } */
    data= other.data;
    dim= other.dim;
    return *this;
}
bool NDvector::operator==(const NDvector& other) const
{
    bool out= true;
    if (dim == other.dim) {
        for (int i= 0; i < dim; i++) {
            if (data[i] != other.data[i]) out= false;
        }
    } else
        out= false;
    return out;
}
ostream& operator<<(ostream& out, const NDvector& v)
{
    out << '(';
    int i;
    for (i= 0; i < v.dim - 1; i++) { out << v.data[i] << ','; }
    out << v.data[i] << ')';
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
