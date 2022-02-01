#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> m;
    m[1] = "kartikey";
    m[2] = "hello";
    m[3] = "how";
    m[4] = "are";
    m[5] = "you";
    m.insert({6, "New way of inserting"});

    cout << "map will be and it is sorted map" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << "\n After erasing " << endl;
    m.erase(3); // pass only key
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << " \nChecking whether any particular  element is present or not ->";
    cout << m.count(4) << endl;

    cout << "Finding the index of any key and the loop through end" << endl;
    auto it = m.find(2);
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " ";
    }

    return 0;
}