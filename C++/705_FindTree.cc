
#include <iostream>
#include <vector>
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
        {"XQAESLKURYIZ", "SEAN","DOT", "IOAS",};
    for (string str : str) cout << check_word(board, str) << endl;
    return 0;
}
struct Point
{
    int i= 0;
    int j= 0;
};
vector<Point> pd(const char c, const vector<vector<char>>& board,
                 const Point point)
{
    vector<Point> s;
    int i= point.i, j= point.j;
    Point tmp;
    if (i > 0) {
        if (board[i - 1][j] == c) {
            tmp.i= i - 1;
            tmp.j= j;
            s.push_back(tmp);
        }
        if (j > 0)
            if (board[i - 1][j - 1] == c) {
                tmp.i= i - 1;
                tmp.j= j - 1;
                s.push_back(tmp);
            }
        if (j < board[0].size() - 1)
            if (board[i - 1][j + 1] == c) {
                tmp.i= i - 1;
                tmp.j= j + 1;
                s.push_back(tmp);
            }
    }
    if (i + 1 < board.size()) {
        if (board[i + 1][j] == c) {
            tmp.i= i + 1;
            tmp.j= j;
            s.push_back(tmp);
        }
        if (j > 0)
            if (board[i + 1][j - 1] == c) {
                tmp.i= i + 1;
                tmp.j= j - 1;
                s.push_back(tmp);
            }
        if (j < board[0].size() - 1)
            if (board[i + 1][j + 1] == c) {
                tmp.i= i + 1;
                tmp.j= j + 1;
                s.push_back(tmp);
            }
    }
    if (j > 0)
        if (board[i][j - 1] == c) {
            tmp.i= i;
            tmp.j= j - 1;
            s.push_back(tmp);
        }
    if (j < board[0].size() - 1)
        if (board[i][j + 1] == c) {
            tmp.i= i;
            tmp.j= j + 1;
            s.push_back(tmp);
        }
    return s;
}
bool sub_check(const vector<vector<char>>& board, const string& word,
               const Point point)
{
    string Word= word.substr(1, word.size() - 1);
    if (Word.length() == 0) return true;
    int i= point.i, j= point.j;
    vector<vector<char>> Board= board;
    Board[i][j]= ' ';
    vector<Point> next= pd(Word[0], Board, point);
    if (! next.empty()) {
        for (Point s_tmp : next) {
            if (sub_check(Board, Word, s_tmp)) return true;
        }
    }
    return false;
}
bool check_word(const vector<vector<char>>& board, const string& word)
{
    vector<Point> start;
    Point start_tmp;
    for (int i= 0; i < board.size(); i++) {
        for (int j= 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0]) {
                start_tmp.i= i;
                start_tmp.j= j;
                start.push_back(start_tmp);
            }
        }
    }
    if (start.empty()) return false;
    for (Point s0 : start) { return sub_check(board, word, s0); }
}