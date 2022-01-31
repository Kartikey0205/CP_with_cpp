#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> maxi; // max-Heap

    priority_queue<int, vector<int>, greater<int>> mini; // min-Heap

    maxi.push(1);
    maxi.push(4);
    maxi.push(2);
    maxi.push(18);

    cout << "Max Heap or Max Priority Queue value will be " << endl;
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }

    mini.push(47);
    mini.push(96);
    mini.push(62);
    mini.push(27);

    cout << "\nMin Heap or Min Priority Queue value will be " << endl;
    int m = mini.size();
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }

    return 0;
}