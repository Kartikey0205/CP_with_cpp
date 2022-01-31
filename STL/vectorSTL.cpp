#include <iostream>
#include <vector>
using namespace std;
int main()
{

    /*
    Vector is dynamic Array, here memory becomes double according to their upcoming requirement
    And if needed some memory then is directly double it memory

    size -> it tells about total number of element present in the vector
    capacity -> it tells about total memory of the vector

    */
    // vector Initializaton
    vector<int> v;
    cout << "Before Pushing" << endl;
    cout << "Size of vector v is :" << v.size() << endl;
    cout << "Capacity of vector v is :" << v.capacity() << endl;

    cout << "After Pushing" << endl;

    // Pushing Element
    v.push_back(2);
    cout << "Size of vector v is :" << v.size() << endl;
    cout << "Capacity of vector v is :" << v.capacity() << endl;

    // Pushing Element
    v.push_back(6);
    cout << "Size of vector v is :" << v.size() << endl;
    cout << "Capacity of vector v is :" << v.capacity() << endl;

    // Pushing Element
    v.push_back(9);
    cout << "Size of vector v is :" << v.size() << endl;
    cout << "Capacity of vector v is :" << v.capacity() << endl;

    // Poping Element
    v.pop_back();
    cout << "After popping" << endl;
    cout << "Size of vector v is :" << v.size() << endl;
    cout << "Capacity of vector v is :" << v.capacity() << endl;
    v.push_back(59);
    v.push_back(95);
    v.push_back(91);

    cout << "Vector is : " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }

    cout << "\nElement at position 2 : " << v.at(2) << endl;

    cout << "\nFirst Element of STL Vector is : " << v.front() << endl;
    cout << "\nLast Element of STL Vector is : " << v.back() << endl;

    cout << "Clearing Vector : it will clear the size but capacity remains same " << endl;
    v.clear();
    cout << "Size of vector v is :" << v.size() << endl;
    cout << "Capacity of vector v is :" << v.capacity() << endl;

    // OTHER WAY OF INITIALIZING VECTOR IS
    vector<int> a(7, 1); //  7 elements and each has value = 1

    cout << "New Vector is : " << endl;
    cout << "Size of vector v is :" << a.size() << endl;
    cout << "Capacity of vector v is :" << a.capacity() << endl;
    for (int i : a)
    {
        cout << i << " ";
    }

    // Copying one vector in other
    vector<int> last(a);
    cout << "\nCopied Vector is : " << endl;

    for (int i : last)
    {
        cout << i << " ";
    }

    return 0;
}