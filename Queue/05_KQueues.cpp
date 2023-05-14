//~ KQueues

//& Approach-1 : Inefficient

//* A simple way to implement k queues is to divide the array in k slots of size n/k each, and fix the slots for different queues, i.e., use arr[0] to arr[n/k-1] for the first queue, and arr[n/k] to arr[2n/k-1] for queue2 where arr[] is the array to be used to implement two queues and size of array be n.

//* The problem with this method is an inefficient use of array space. An enqueue operation may result in overflow even if there is space available in arr[]. For example, consider k as 2 and array size n as 6. Let we enqueue 3 elements to first and do not enqueue anything to the second queue. When we enqueue the 4th element to the first queue, there will be overflow even if we have space for 3 more elements in the array.

//& Approach-1 :

//* Similar to one which we use for KStacks
//* we need to use three extra arrays. In stack, we needed two extra arrays, one more array is required because in queues, enqueue() and dequeue() operations are done at different ends.

//* front[]: This is of size k and stores indexes of front elements in all queues.
//* rear[]: This is of size k and stores indexes of rear elements in all queues.
//* next[]: This is of size n and stores indexes of next item for all items in array arr[].

//* All entries in front[] are initialized as -1 to indicate that all queues are empty. All entries next[i] are initialized as i+1 because all slots are free initially and pointing to the next slot. Top of the free stack, ‘free’ is initialized as 0.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class KQueues
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n, k;
    int free;

public:
    KQueues(int k, int n);
    bool isFull();
    void enQueue(int x, int qn);
    int deQueue(int qn);
    bool isEmpty(int qn);
};

KQueues::KQueues(int k1, int n1)
{
    k = k1, n = n1;
    arr = new int[n];
    front = new int[k];
    rear = new int[k];
    next = new int[n];
    for (int i = 0; i < k; i++)
    {
        front[i] = -1;
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

bool KQueues::isFull()
{
    return (free == -1);
}

bool KQueues::isEmpty(int qn)
{
    return (front[qn] == -1);
}

//* O(1)
void KQueues::enQueue(int x, int qn)
{
    if (isFull())
    {
        cout << "Queue Overflow!!";
        return;
    }
    int i = free;
    //* Update index of free slot to index of next slot in free list
    free = next[i];
    if (isEmpty(qn))
    {
        front[qn] = i;
    }
    else
    {
        //* Linking next rear with previous
        next[rear[qn]] = i;
    }
    next[i] = -1;
    //* Setting new rear after enqueue
    rear[qn] = i;
    arr[i] = x;
}

//* O(1)
int KQueues::deQueue(int qn)
{
    if (isEmpty(qn))
    {
        cout << "Queue Underflow" << endl;
        return INT_MIN;
    }
    int i = front[qn];
    //* Finding next front which we already set above
    front[qn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int k = 3, n = 10;
    KQueues ks(k, n);
    ks.enQueue(15, 2);
    ks.enQueue(45, 2);
    ks.enQueue(17, 1);
    ks.enQueue(49, 1);
    cout << "Dequeued element from queue 1 is " << ks.deQueue(1) << endl;
    cout << "Dequeued element from queue 1 is " << ks.deQueue(1) << endl;
    ks.enQueue(39, 1);
    cout << "Dequeued element from queue 1 is " << ks.deQueue(1) << endl;
    ks.enQueue(11, 0);
    ks.enQueue(9, 0);
    ks.enQueue(7, 0);
    cout << "Dequeued element from queue 2 is " << ks.deQueue(2) << endl;
    cout << "Dequeued element from queue 0 is " << ks.deQueue(0) << endl;
    return 0;
}