#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int m, n, i, j;
    int k;
    cin >> m >> n;
    int a[m][n];
    for (i= 0; i < m; i++)
        for (j= 0; j < n; j++) cin >> a[i][j];
    for (i= 0; i < m; i++) {
        for (j= 0; j < n; j++) {
            cout << setw(3) << setfill('0') << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
//? better than blow?
/* 
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int m, n, i, j;
    int k;
    cin >> m >> n;
    int a[m][n];
    for (i= 0; i < m; i++) {
        for (j= 0; j < n; j++) {
            cin >> a[i][j];
            cout << setw(3) << setfill('0') << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
 */