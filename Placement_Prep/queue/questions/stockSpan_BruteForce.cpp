#include <iostream>
using namespace std;
int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        int days = 0;
        for (int j = i; j >= 0; j--)
        {
            if (price[i] >= price[j])
            {

                days++;
                ans[i] = days;
                // cout << days;
            }

            else
            {

                break;
            }
        }
    }

    cout << "Span for all stock are ";
    for (auto i : ans)
        cout << i << " ";
    return 0;
}