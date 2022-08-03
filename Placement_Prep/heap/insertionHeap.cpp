// O(log n)

#include <iostream>
using namespace std;
class heap
{
public:
    int Heap[100];
    int size;
    heap()
    {
        Heap[0] = -1;
        size = 0;
    }
    // Insertion in Heap
    void insert_Heap(int val)
    {
        size = size + 1;
        int index = size;
        Heap[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (Heap[index] > Heap[parent])
            {
                swap(Heap[index], Heap[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        cout << "Value in Max Heap is :" << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << Heap[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert_Heap(10);
    h.insert_Heap(15);
    h.insert_Heap(21);
    h.insert_Heap(30);
    h.insert_Heap(18);
    h.insert_Heap(19);
    h.print();
    return 0;
}