#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define repeat(i, a, b) for (int i = a; i < b; i++)

void heapify(vector<int> &a, int size, int i)
{
    int largestNode = i;
    int leftNode = 2 * i + 1;
    int rightNode = 2 * i + 2;

    if (leftNode < size && a[largestNode] < a[leftNode])
    {
        largestNode = leftNode;
    }
    if (rightNode < size && a[largestNode] < a[rightNode])
    {
        largestNode = rightNode;
    }

    // check whether largest node got change or not
    if (largestNode != i)
    {
        swap(a[largestNode], a[i]);
        heapify(a, size, largestNode);
    }
}
void heapSort(vi &a)
{
    int n = a.size();

    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
signed main()
{
    int n;
    cin >> n; // 6
    vi a(n);  // 4 5 3 2 6 1

    repeat(i, 0, n)
            cin >>
        a[i];

    heapSort(a);

    repeat(i, 0, n)
            cout
        << a[i] << " ";
    return 0;
}