#include <iostream>
#include <stack>
using namespace std;
int main()
{

    stack<int> s;
    s.push(6);
    s.push(69);
    s.push(61);
    s.push(63);
    s.push(56);
    s.push(76);

    cout << "Size of stack before popping will be : " << endl;
    cout << s.size() << endl;
    cout << "Top element of stack will be : " << endl;
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();

    cout << "Size of stack after popping will be : " << endl;
    cout << s.size() << endl;

    cout << "Stack is empty or not : " << endl;
    cout << s.empty() << endl;
    return 0;
}