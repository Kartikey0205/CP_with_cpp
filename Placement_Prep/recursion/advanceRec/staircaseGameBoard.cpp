#include <iostream>
using namespace std;
int staircase(int st, int en)
{
    if (st == en)
    {
        return 1;
    }
    if (st > en)
    {
        return 0;
    }

    // DICE BASED
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += staircase(st + i, en);
    }
    return count;
}
int main()
{
    int st = 0, en = 3;
    cout << staircase(st, en);
    return 0;
}