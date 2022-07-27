#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int histogram[] = {2, 1, 5, 6, 2, 3};
    int ans = 0, n = sizeof(histogram) / sizeof(histogram[0]);

    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(histogram[j], minHeight);
            int width = j - i + 1;
            ans = max(ans, width * minHeight);
        }
    }
    cout << ans << endl;
    return 0;
}