#include <iostream>
using namespace std;
int knapsack_0_1(int val[], int wt[], int maxWt, int item)
{
    if (item == 0 || maxWt == 0)
    {
        return 0;
    }
    if (wt[item - 1] > maxWt)
    {
        return knapsack_0_1(val, wt, maxWt, item - 1);
    }
    return max((knapsack_0_1(val, wt, maxWt - wt[item - 1], item - 1) + val[item - 1]), knapsack_0_1(val, wt, maxWt, item - 1));
}
int main()
{
    int wt[] = {10, 20, 30};
    int val[] = {100, 50, 150};
    int maxWt = 50;
    int item = 3;
    cout << knapsack_0_1(val, wt, maxWt, item);
    return 0;
}