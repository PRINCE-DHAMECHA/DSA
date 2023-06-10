//~ Create a data structure kStacks that represents k stacks. Implementation of kStacks should use only one array, i.e., k stacks should use the same array for storing elements.
//~ The following functions must be supported by k Stacks. push(int x, int sn) –> pushes x to stack number ‘sn’ where sn is from 0 to k-1 pop(int sn) –> pops an element from stack number ‘sn’ where sn is from 0 to k-1

//* Method 1 (Divide the array in slots of size n/k) A simple way to implement k stacks is to divide the array in k slots of size n/k each, and fix the slots for different stacks, i.e., use arr[0] to arr[n/k-1] for first stack, and arr[n/k] to arr[2n/k-1] for stack2 where arr[] is the array to be used to implement two stacks and size of array be n. The problem with this method is inefficient use of array space. A stack push operation may result in stack overflow even if there is space available in arr[]. For example, say the k is 2 and array size (n) is 6 and we push 3 elements to first and do not push anything to second stack. When we push 4th element to first, there will be overflow even if we have space for 3 more elements in array.

//* Method 2 (A space-efficient implementation) The idea is to use two extra arrays for efficient implementation of k stacks in an array. This may not make much sense for integer stacks, but stack items can be large for example stacks of employees, students, etc where every item is of hundreds of bytes. For such large stacks, the extra space used is comparatively very less as we use two integer arrays as extra space.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class KStacks
{
    //* Array of size n to store actual content to be stored in stacks
    int *arr;
    //* Array of size k to store indexes of top elements of stacks
    int *top;
    //* Array of size n to store next entry in all stacks and free list
    int *next;
    int n, k;
    //* To store beginning index of free list
    int free;

public:
    //* constructor to create k stacks in an array of size n
    KStacks(int k, int n);

    //* A utility function to check if there is space available
    bool isFull() { return (free == -1); }

    //* To push an item in stack number 'sn' where sn is from 0 to k-1
    void push(int item, int sn);

    //* To pop an from stack number 'sn' where sn is from 0 to k-1
    int pop(int sn);

    //* To check whether stack number 'sn' is empty or not
    bool isEmpty(int sn) { return (top[sn] == -1); }
};

KStacks::KStacks(int k1, int n1)
{
    k = k1, n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    for (int i = 0; i < k; i++)
    {
        top[i] = -1;
    }
    //* Initialize all spaces as free
    free = 0;
    for (int i = 0; i < n - 1; i++)
    {
        next[i] = i + 1;
    }
    //! -1 is used to indicate end of free list
    next[n - 1] = -1;
}

void KStacks::push(int x, int sn)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    int i = free;
    free = next[i];
    //* We're just remembering previous top of current stack using next, so every time we update top we store that first in corresponding next
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = x;
}

int KStacks::pop(int sn)
{
    if (isEmpty(sn))
    {
        cout << "Stack Underflow" << endl;
        return INT_MAX;
    }
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    //* Now top before pop will be free so we can add element there
    free = i;
    return arr[i];
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    int k = 3, n = 10;
    KStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}