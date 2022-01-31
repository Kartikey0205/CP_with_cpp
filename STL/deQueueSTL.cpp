#include <iostream>
#include <deque>
using namespace std;
int main()
{

    // In Dequeue we acan insert delete from any side also known as doubly ended queue
    deque<int> d;

    // Pushing Elements
    d.push_back(3);
    d.push_front(8);
    d.push_back(34);
    d.push_front(85);
    d.push_back(38);
    d.push_front(38);
    d.push_back(13);
    d.push_front(28);

    cout << "Dequeue will be : " << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Element at index 1 = " << d.at(1) << endl;

    cout << "\nFirst Element of STL Dequeue is : " << d.front() << endl;
    cout << "\nLast Element of STL Dequeue is : " << d.back() << endl;

    cout << "After Popping " << endl;
    d.pop_front();
    d.pop_back();
    d.pop_front();
    cout << "Dequeue will be : " << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "\nSTL Dequeue Size is : " << d.size() << endl;
    cout << "\nSTL Dequeue is empty or not -> " << d.empty() << endl;

    // Erasing Dequeue
    d.erase(d.begin(), d.begin() + 3); // Earse function will take 2 argument -> first where to start an d2nd till what
    cout << "After erasing dequeue element " << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    return 0;
}