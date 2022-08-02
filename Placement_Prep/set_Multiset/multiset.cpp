#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(5);
    s.insert(5);

    s.insert(5);
    s.insert(7);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << s.size();
    cout << endl;

    s.erase(2); // delete all occcurence
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
    s.erase(s.find(5));

    for (auto i = s.rbegin(); i != s.rend(); i++)
        cout << *i << " ";
    cout << endl;

    set<int, greater<int>> st;

    st.insert(1);
    st.insert(2);
    st.insert(2);
    st.insert(5);
    st.insert(7);
    for (auto i = st.begin(); i != st.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << *st.lower_bound(2);
    cout << endl;

    cout << *st.lower_bound(5);

    return 0;
}