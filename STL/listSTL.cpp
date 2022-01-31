#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(2);
    l.push_front(39);
    l.push_back(25);
    l.push_front(459);
    l.push_back(27);
    l.push_front(91);
    l.push_back(23);
    l.push_front(99);
    l.push_back(28);
    l.push_front(69);
    l.push_back(72);
    l.push_front(49);

    cout << "List will be " << endl;
    for (auto i : l)
    {
        cout << i << " ";
    }

    cout << "\nAfter erasing from begining " << endl;
    l.erase(l.begin());
    for (auto i : l)
    {
        cout << i << " ";
    }

    cout << "\nAfter popping few element from back and front " << endl;
    l.pop_back();
    l.pop_front();
    l.pop_back();
    l.pop_front();
    for (auto i : l)
    {
        cout << i << " ";
    }

    cout << "Size of List is " << l.size() << endl;

    cout << "Copy list will be " << endl;
    list<int> n(l);
    for (auto i : n)
    {
        cout << i << " ";
    }

    cout << "\nCreating  new list with with another way" << endl;
    list<int> newList(5, 100);
    for (auto i : newList)
    {
        cout << i << " ";
    }
    return 0;
}