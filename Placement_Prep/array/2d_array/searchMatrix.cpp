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
    cout << "Matrix is " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int num;
    cout << "Enter the number ";
    cin >> num;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == num)
            {
                cout << "Found";
                flag = true;
                return 0;
            }
        }
    }
    if (flag == false)
    {
        cout << "Not Found";
    }
    return 0;
}