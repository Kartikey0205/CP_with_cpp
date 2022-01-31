#include <iostream>
#include <queue>
using namespace std;
int main()
{

    queue<int> q;
    q.push(6);
    q.push(69);
    q.push(61);
    q.push(63);
    q.push(56);
    q.push(76);

    cout << "Size of queue before popping will be : " << endl;
    cout << q.size() << endl;
    cout << "Front element of queue will be : " << endl;
    cout << q.front() << endl;

    q.pop();
    q.pop();
    q.pop();
    cout << "Back element of queue will be : " << endl;
    cout << q.back() << endl;

    cout << "Size of queue after popping will be : " << endl;
    cout << q.size() << endl;

    cout << "queue is empty or not : " << endl;
    cout << q.empty() << endl;
    return 0;
}