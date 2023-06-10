//~ Operations on Heap(Min):

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class MinHeap
{
    //* Pointer to array of elements in heap
    int *harr;
    //* To define max size
    int capacity;
    //* Current Size
    int heapSize;

public:
    MinHeap(int capacity);
    void MinHeapify(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    int extractMin();
    void derceaseKeyAtIndex(int i, int newVal);
    int getMin();
    void deleteKeyAtIndex(int i);
    void insertKey(int k);
    void printHeap()
    {
        for (int i = 0; i < heapSize; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }
};

//* Constructor
MinHeap::MinHeap(int capacity)
{
    this->capacity = capacity;
    heapSize = 0;
    harr = new int[capacity];
}

//* Find parent of given node
int MinHeap::parent(int i)
{
    return (i - 1) / 2;
}

//* to get index of left child of node at index i
int MinHeap::left(int i)
{
    return (2 * i + 1);
}

//* to get index of right child of node at index i
int MinHeap::right(int i)
{
    return (2 * i + 2);
}

//* Return min or root
int MinHeap::getMin()
{
    return harr[0];
}

//* Insert given key in heap
void MinHeap::insertKey(int k)
{
    if (heapSize == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    //* Insert temporary at last
    heapSize++;
    int i = heapSize - 1;
    harr[i] = k;

    //* Fix the min heap property if it is violated
    //* If parent is greater than child than we need to swap according to MinHeap property
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

//* Decrease value of ith node to newVal
//* We assume that newVal is smaller than harr[i]
void MinHeap::derceaseKeyAtIndex(int i, int newVal)
{
    harr[i] = newVal;
    //* Fix the min heap property if it is violated
    //* If parent is greater than child than we need to swap according to MinHeap property
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

//* Find and delete minimum value from heap which is root
//* We ensure that after deletion it'll satisfy all the heap property
int MinHeap::extractMin()
{
    if (heapSize <= 0)
    {
        return INT_MAX;
    }
    if (heapSize == 1)
    {
        //* Only element will be root and we'll return that
        return harr[--heapSize];
    }
    //* Store minimum value
    int root = harr[0];
    //* Bring last element and decrease heapSize
    harr[0] = harr[heapSize - 1];
    heapSize--;
    //* Heapify given array
    MinHeapify(0);
    return root;
}

//* Delete given key store
void MinHeap::deleteKeyAtIndex(int i)
{
    //* Set given index to infinite
    derceaseKeyAtIndex(i, INT_MIN);
    //* Now this infinite will be our minimum and we know extractMin will remove minimum element
    //* Bingo!!
    extractMin();
}

//* A recursive method to heapify a subtree with the root at given index
//! This method already assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    //* FInd smallest between l,r and i
    if (l < heapSize && harr[l] < harr[i])
    {
        smallest = l;
    }
    if (r < heapSize && harr[r] < harr[smallest])
    {
        smallest = r;
    }
    //* If one of the child is smallest then swap it with parent
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        //* Recursively heapify child
        MinHeapify(smallest);
    }
}

//~ Approach:
//* We use Min heap to sort given array, We insert all element in heap and extract min one by one by heapify
//* Pretty much straight forward

void heapSort(vector<int> &nums)
{
    MinHeap *mh = new MinHeap(nums.size());
    for (auto i : nums)
    {
        mh->insertKey(i);
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = (mh->extractMin());
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> nums = {10, 33, 3, 4, 24, 4, 5, 5, 7, 8, 9, 1, 5};
    heapSort(nums);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}