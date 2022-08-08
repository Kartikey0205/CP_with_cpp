#include <bits/stdc++.h>
using namespace std;
int main()
{
    int totalActivity;
    cin >> totalActivity;

    vector<vector<int>> timeStamp;
    for (int i = 0; i < totalActivity; i++)
    {
        int start, end;
        cin >> start >> end;

        timeStamp.push_back({start, end});
    }

    // sort by custom made comparator (comparing end time)

    sort(timeStamp.begin(), timeStamp.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int take = 1;
    int firstAct = timeStamp[0][1];

    for (int activityNum = 1; activityNum < totalActivity; activityNum++)
    {
        if (timeStamp[activityNum][0] >= firstAct)
        {
            take++;
            firstAct = timeStamp[activityNum][1];
        }
    }

    cout << "Total Activity Selected is " << take << endl;
    return 0;
}