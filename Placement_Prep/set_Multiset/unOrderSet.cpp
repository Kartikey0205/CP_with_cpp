#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);

    s.insert(5);
    s.insert(7);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << s.size();
    cout << endl;

    s.erase(2);
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;

     return 0;
}