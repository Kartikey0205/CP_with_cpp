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

    // Deletion in HEAP
    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete" << endl;
            return;
        }

        // step 1 - swap arr[1] and arr[last];  --> O(1)
        Heap[1] = Heap[size];
        // step 2 - delete last Node --> O(1)
        size--;

        // Step 3 - put heap[1] to its correct position --> O(log n)
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && Heap[i] < Heap[leftIndex])
            {
                swap(Heap[i], Heap[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex <= size && Heap[i] < Heap[rightIndex])
            {
                swap(Heap[i], Heap[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
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

    h.deleteHeap();
    cout << "After Deletion " << endl;
    h.print();
    return 0;
}