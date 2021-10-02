#include <iostream>
using namespace std;
class Matrix
{
 private:
    int row, col;
    int** data;

 public:
    Matrix();        //构造一个空矩阵（row = col = 0 , data = NULL ）
    Matrix(int Row, int Col);        // 构造一个Row行Col列的矩阵，所有元素为0
    Matrix(
        int Row, int Col,
        int** elements);        //从一个Row * Col的二维数组elements构造一个矩阵
    Matrix(const Matrix& mat);        //拷贝构造函数
    ~Matrix();                        //析构函数
    bool empty() const;               //判断矩阵是否为空矩阵
    int& at(int a, int b);            // at(a,b) 表示 得到 a行b列 元素
    Matrix operator+(const Matrix& other)
        const;        //重载矩阵加法，如果传入矩阵other的维度与当前矩阵不相等，则返回一个空矩阵
    Matrix operator*(const Matrix& other)
        const;        //重载矩阵乘法，如果传入矩阵other的行数不等于当前矩阵的列数，则返回一个空矩阵
};
Matrix::Matrix()
{
    row= col= 0, data= NULL;
}
Matrix::Matrix(int Row, int Col) : row(Row), col(Col)
{
    int** newdata= new int*[row];
    for (int i= 0; i < row; i++) {
        for (int j= 0; j < col; j++) { newdata[i][j]= 0; }
    }
    data= newdata;
}
Matrix::Matrix(int Row, int Col, int** elements)
{
    row= Row;
    col= Col;
    int* newdata[row];
    for (int i= 0; i < row; i++) {
        for (int j= 0; j < col; j++) { newdata[i][j]= elements[i][j]; }
    }
    data= newdata;
}
Matrix::Matrix(const Matrix& mat)
{
    row= mat.row;
    col= mat.col;
    int** newdata= new int*[row];
    for (int i= 0; i < row; i++) {
        for (int j= 0; j < col; j++) { newdata[i][j]= mat.data[i][j]; }
    }
    data= newdata;
}
Matrix::~Matrix() {}
bool Matrix::empty() const
{
    if (data == NULL)
        return true;
    else
        return false;
}
int& Matrix::at(int a, int b)
{
    int& p= data[a][b];
    return p;
}
Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix add= Matrix(row, col);
    if (row == other.row && col == other.col) {
        int** newdata= new int*[row];
        for (int i= 0; i < row; i++) {
            for (int j= 0; j < col; j++) {
                newdata[i][j]= data[i][j] + other.data[i][j];
            }
        }
        add.data= newdata;
    } else {
        add.data= NULL;
    }
    return add;
}
Matrix Matrix::operator*(const Matrix& other) const
{
    Matrix chen= Matrix(row, other.col);
    if (col == other.row) {
        int** newdata= new int*[row];
        for (int i= 0; i < row; i++) {
            for (int j= 0; j < other.col; j++) {
                int temp= 0;
                for (int j1= 0; j < other.col; j++) {
                    for (int i2= 0; i2 < row; i2++) {
                        temp+= data[i][j1] * other.data[i2][j];
                    }
                }
                newdata[i][j]= temp;
                temp= 0;
            }
        }
        chen.data= newdata;
    } else {
        chen.data= NULL;
    }
    return chen;
}
