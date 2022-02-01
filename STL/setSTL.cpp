#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(4);
    s.insert(4);
    s.insert(8);
    s.insert(9);
    s.insert(34);
    s.insert(3984);
    s.insert(344);
    s.insert(342);
    s.insert(734);

    cout << "Set will be and it is sorted array" << endl;
    for (auto i : s)
    {
        cout << i << " ";
    }

    cout << "\n After erasing " << endl;
    s.erase(s.begin());
    for (auto i : s)
    {
        cout << i << " ";
    }

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    cout << " \nErasing second element " << endl;

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << " \nChecking whether any particular  element is present or not ";
    cout << s.count(5) << endl;

    cout << "Finding the index of any element and the loop through end" << endl;
    set<int>::iterator itr = s.find(34);
    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}