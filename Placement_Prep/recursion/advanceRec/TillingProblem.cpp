// board 2 * n and tile 2 * 1 rows must be same
#include <iostream>
using namespace std;
int tiling(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    return tiling(n - 1) + tiling(n - 2);
}
int main()
{
    cout << tiling(4);
    return 0;
}