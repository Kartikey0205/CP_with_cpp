// Sorted row and col matrix

#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the row and col ";
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int num;
    cout << "Enter the number ";
    cin >> num;
    bool flag = false;
    int r = 0, c = m - 1;
    while (r < n && c >= 0)
    {
        if (a[r][c] == num)
        {
            flag = true;
        }
        if (a[r][c] > num)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (flag == false)
    {
        cout << "Not Found";
    }
    else
    {
        cout << "Found";
    }
    return 0;
}