
#include <iostream>
using namespace std;
int main()
{
    //动态创建一维数组
    int* A= new int[10];        // int A[10];
    //?动态创建二维数组
    int n= 10, m= 10;
    int** B= new int*[n];        // int* B[n]=new int[m]; int B[n][m];
    for (int i= 0; i < n; ++i) {
        B[i]= new int[m];//! 二次分配内存
        for (int j= 0; j < m; ++j) { B[i][j]= 9; }
    }
    for (int i= 0; i < n; ++i) {
        for (int j= 0; j < n; ++j) { cout << B[i][j] << " "; }
        cout << endl;
    }
    cout << endl;
    //////////////////////////
    {
        //静态创建一维数组
        const int n= 10;
        const int m= 15;
        int a[n]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        //静态创建二维数组
        int b[n][m]= {
            11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
            28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 11, 12, 13, 14,
            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
            32, 33, 34, 35, 36, 37, 38, 39, 40, 11, 12, 13, 14, 15, 16, 17, 18,
            19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
            36, 37, 38, 39, 40, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
            23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
            40, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
            27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
        for (int i= 0; i < n; ++i)        //行
        {
            for (int j= 0; j < m; ++j)        //列
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i= 0; i < m; ++i)        //行
        {
            for (int j= 0; j < n; ++j)        //列
            {
                cout << b[j][i] << " ";
            }
            cout << endl;
        }
    }
    delete[] A;
    delete[] B;
    cout << endl << "ok!" << endl;
    return 0;
}