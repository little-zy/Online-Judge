
#include <iostream>
#include <vector>
#define N 100
using namespace std;
bool check_word(const vector<vector<char>>& board, const string& word);
int main()
{
    vector<vector<char>> board= /*  {{'I', 'L', 'A', 'W'},
                                  {'B', 'N', 'G', 'E'},
                                  {'I', 'U', 'A', 'O'},
                                  {'A', 'S', 'R', 'L'}} */
        {{'X', 'Q', 'A', 'E'},
         {'Z', 'O', 'T', 'S'},
         {'I', 'N', 'D', 'L'},
         {'Y', 'R', 'U', 'K'}};
    string str[]=        // {"BINGO", "LINGO", "SINUS"};
        {
            "XQAESLKURYIZ",
            "SEAN",
            "DOT",
            "IOAS",
        };
    for (string str : str) cout << check_word(board, str) << endl;
    return 0;
}
bool DFS(const vector<vector<char>>& board, const string& word, int x, int y,
         int k, bool visited[][151])
{
    if (k == word.size()) return 1;
    int row= board.size();
    int col= board[0].size();
    int dx[8]= {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i= 0; i < 8; ++i) {
        int tmpx= x + dx[i];
        int tmpy= y + dy[i];
        if (tmpx < 0 || tmpx >= row) continue;
        if (tmpy < 0 || tmpy >= col) continue;
        if (visited[tmpx][tmpy]) continue;
        if (board[tmpx][tmpy] != word[k]) continue;
        visited[tmpx][tmpy]= 1;
        if (DFS(board, word, tmpx, tmpy, k + 1, visited)) {
            visited[tmpx][tmpy]= 0;
            return 1;
        }
        visited[tmpx][tmpy]= 0;
    }
    return 0;
}
bool check_word(const vector<vector<char>>& board, const string& word)
{
    int row= board.size();
    int col= board[0].size();
    bool flag= 0;
    bool visited[151][151]= {};
    for (int i= 0; i < row; ++i)
        for (int j= 0; j < col; ++j) {
            if (board[i][j] == word[0]) {
                visited[i][j]= 1;
                flag= DFS(board, word, i, j, 1, visited);
                visited[i][j]= 0;
            }
            if (flag) return true;
        }
    return false;
}
/* bool DFS(const vector<vector<char>>& board, const string& word, int x, int y,
         int k, bool visited[][N])
{
    int row= board.size(), col= board[0].size();
    if (k == row) return true;
    int x_tmp, dx[8]= {-1, -1, -1, 0, 0, 1, 1, 1};
    int y_tmp, dy[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
    int i= 0;
    for (i= 0; i < 8; ++i) {
        x_tmp= x + dx[i];
        y_tmp= y + dy[i];
        if (x_tmp < 0 || x_tmp >= row) continue;
        if (y_tmp < 0 || y_tmp >= col) continue;
        if (visited[x_tmp][y_tmp]) continue;
        if (board[x_tmp][y_tmp] != word[k]) continue;
        visited[x_tmp][y_tmp]= 1;
        if (DFS(board, word, x_tmp, y_tmp, k + 1, visited)) {
            visited[x_tmp][y_tmp]= 0;
            return true;
        }
        visited[x_tmp][y_tmp]= 0;
    }
    return false;
}
bool check_word(const vector<vector<char>>& board, const string& word)
{
    int row= board.size();
    int col= board[0].size();
    bool visited[N][N]= {};
    for (int i= 0; i < row; ++i)
        for (int j= 0; j < col; ++j)
            if (board[i][j] == word[0]) {
                visited[i][j]= 1;
                if (DFS(board, word, i, j, 1, visited)) return true;
                visited[i][j]= 0;
            }
    return false;
} */