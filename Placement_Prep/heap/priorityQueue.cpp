/*
PUSH - O(log n)
POP - O(log n)
TOP- O(1)
SIZE - O(1)

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Max Heap
    cout << "Max Heap " << endl;
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(22);
    pq.push(90);
    pq.push(13);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << endl;
    // Min Heap
    cout << "Min Heap " << endl;

    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(2);
    pq_min.push(22);
    pq_min.push(90);
    pq_min.push(13);
    cout << pq_min.top() << endl;
    pq_min.pop();
    cout << pq_min.top() << endl;

    return 0;
}