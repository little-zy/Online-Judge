
#include <iostream>
#include <vector>
using namespace std;
int mu(const vector<int>* Ai, int Column_A, const vector<vector<int>>* B,
       int column)
{
    int result= 0;
    for (int i= 0; i < Column_A; i++) { result+= (*Ai)[i] * (*B)[i][column]; }
    return result;
}
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B)
{
    int line= 0, column= 0;
    int Line_A= A.size(), Column_A= A[0].size(), Column_B= B[0].size();
    // vector<vector<int> > vec(row,vector<int>(col,0))
    vector<vector<int>> C(Line_A);        //, vector<int>(Column_B, 0));
    for (; line < Line_A; line++)
        for (column= 0; column < Column_B; column++)
            C[line].push_back(mu(&A[line], Column_A, &B, column));
    return C;
}
int main()
{
    vector<vector<int>> A= {{2, 1, 4, 0}, {1, -1, 3, 4}},
                        B= {{1, 3, 1}, {0, -1, 2}, {1, -3, 1}, {4, 0, -2}};
    vector<vector<int>> C= multiply(A, B);
    int Line_A= A.size(), Column_B= B[0].size();
    // vector<vector<int> > vec(row,vector<int>(col,0))
    // vector<vector<int>> C(Line_A, vector<int>(Column_B, 0));
    for (int line= 0; line < Line_A; line++) {
        for (int column= 0; column < Column_B; column++) {
            cout << C[line][column] << ' ';
        }
        cout << endl;
    }
    // answer=  6  -7  8
    //          20 -5 -6
    return 0;
}