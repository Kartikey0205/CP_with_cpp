#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str, s1 = "good", s2 = "Heelo";
    cout << "Enter your String ";
    getline(cin, str);
    // Append function
    cout << str.append(s1) << endl;
    cout << str + s1 << endl;

    // Clear function
    s2.clear();
    cout << s2 << endl;

    // Compare function
    cout << str.compare(s1) << endl; // str ko comapre kr rhe h s1 se

    // Empty Function
    if (s2.empty())
        cout << "Empty" << endl;
    else
        cout << "Not empty" << endl;

    // Erase Function
    str.erase(3, 3);
    cout << str << endl;

    // find Function
    cout << "First Index where substring found is " << s1.find("oo") << endl;

    // Insert Function
    s2.insert(0, "inserted Succesfully");
    cout << s2 << endl;
    for (int i = 0; i < s1.size(); i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;

    // substr Function
    cout << str.substr(2, 8) << endl;

    string int_S = "786";
    // conversion to int
    cout << stoi(int_S) + 7 << endl;

    int x = 785;
    // conversion to string
    cout << to_string(x) + "2" << endl;

    // Sort Function

    sort(str.begin(), str.end());
    cout << str << endl;

    string s = "87872987780198910";
    // ascending order
    sort(s.begin(), s.end());
    cout << s << endl;
    // descending order
    sort(s.begin(), s.end(), greater<int>());
    cout << s << endl;

    // Upper case transformation
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << endl;
    // Lower case transformation
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;
    return 0;
}