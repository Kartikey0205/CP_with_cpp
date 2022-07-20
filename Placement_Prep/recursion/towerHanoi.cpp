#include <bits/stdc++.h>
using namespace std;
void TOH(int num, string src, string end, string aux)
{
    if (num == 0)
    {
        return;
    }
    TOH(num - 1, src, aux, end);
    cout << src << " to " << end << endl;
    TOH(num - 1, aux, end, src);
}
int main()
{
    TOH(3, "A", "C", "B");
    return 0;
}