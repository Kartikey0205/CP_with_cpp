#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> price)
{
    vector<int> result;
    stack<pair<int, int>> st; // { pair of pricevalue and day}
    for (auto priceValue : price)
    {
        int days = 1;
        // stack not empty
        while (!st.empty() and st.top().first <= priceValue)
        {
            days += st.top().second;
            st.pop();
        }
        // stack empty
        st.push({priceValue, days});
        result.push_back(days);
    }

    return result;
}
int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockSpan(price);
    cout << "Span for all Stocks is ";
    for (auto day : ans)
    {
        cout << day << " ";
    }
    return 0;
}