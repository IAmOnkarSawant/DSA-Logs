#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> ds; // zero based indexing
    void heapifyUp(int index)
    {
        if (index < 0)
            return;
        int parent = (index - 1) / 2;
        if (ds[parent] < ds[index])
        {
            swap(ds[parent], ds[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int n = ds.size();

        if (left < n && ds[left] > ds[largest])
            largest = left;
        if (right < n && ds[right] > ds[largest])
            largest = right;

        if (largest != i)
        {
            swap(ds[largest], ds[i]);
            heapifyDown(largest);
        }
    }

    int left(int index)
    {
        return (index * 2) + 1;
    }
    int right(int index)
    {
        return (index * 2) + 2;
    }

public:
    Heap(vector<int> &vec)
    {
        build_heap(vec);
    }

    void build_heap(vector<int> &nums)
    {
        ds = nums; // deep copy
        int n = nums.size();
        int last_non_leaf = n / 2 - 1; // index
        for (int i = last_non_leaf; i >= 0; i--)
            heapifyDown(i);
    }

    void print()
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << "\n";
    }

    int top()
    {
        return ds[0];
    }

    bool push(int val)
    {
        ds.push_back(val);
        heapifyUp(ds.size() - 1);
        return 1;
    }

    bool pop()
    {
        if (ds.size() <= 0)
            return 0;
        swap(ds[0], ds[ds.size() - 1]);
        ds.pop_back();
        if (!ds.empty())
            heapifyDown(0);
        return 1;
    }

    bool decrease_key(int index, int value)
    {
        if(index < 0 || index >= ds.size()) // index outof bounds
            return 0;
        if(value > ds[index]) // cant be greater value than existing 
            return 0;

        ds[index] = value;
        heapifyDown(index);
    }
};

int main()
{
    vector<int> nums = {3, 1, 5, 7, 2, 4, 6};
    Heap* h = new Heap(nums);

    h->print();  // Print the heap after construction

    h->push(10);  // Push a new element
    h->print();   // Print the heap after push

    h->pop();     // Pop the top element
    h->print();   // Print the heap after pop

    // Test decrease key
    h->decrease_key(3, 0);  // Decrease the key at index 3 to 0
    h->print();             // Print the heap after decreasing the key

    return 0;
}