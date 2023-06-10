//~ Create a data structure twoStacks that represent two stacks. Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* The idea to implement two stacks is to divide the array into two halves and assign two halves to two stacks, i.e., use arr[0] to arr[n/2] for stack1, and arr[(n/2) + 1] to arr[n-1] for stack2 where arr[] is the array to be used to implement two stacks and size of array be n.

class TwoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

void TwoStacks::push1(int x)
{
    if (top1 > 0)
    {
        arr[--top1] = x;
    }
    else
    {
        cout << "Stack Overflow!!" << endl;
        return;
    }
}

void TwoStacks::push2(int x)
{
    if (top2 < size - 1)
    {
        arr[++top2] = x;
    }
    else
    {
        cout << "Stack Overflow!!" << endl;
        return;
    }
}

int TwoStacks::pop1()
{
    if (top1 <= size / 2)
    {
        int x = arr[top1++];
        return x;
    }
    else
    {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
}

int TwoStacks::pop2()
{
    if (top1 >= size / 2 + 1)
    {
        int x = arr[top2--];
        return x;
    }
    else
    {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ": " << ts.pop1() << endl;
    ts.push2(40);
    cout << "Popped element from stack2 is "
         << ": " << ts.pop2() << endl;
    return 0;
}