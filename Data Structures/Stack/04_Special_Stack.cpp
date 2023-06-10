//~ Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, etc.

//* Use two stacks: one to store actual stack elements and the other as an auxiliary stack to store minimum values.

// When we insert 18, both stacks change to following.
// Actual Stack
// 18 <--- top
// Auxiliary Stack
// 18 <---- top

// When 19 is inserted, both stacks change to following.
// Actual Stack
// 19 <--- top
// 18
// Auxiliary Stack
// 18 <---- top
// 18

// When 29 is inserted, both stacks change to following.
// Actual Stack
// 29 <--- top
// 19
// 18
// Auxiliary Stack
// 18 <---- top
// 18
// 18

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    bool pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void print();
};

bool Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        cout << "Stack Overflow" << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " Pushed into stack" << endl;
        return true;
    }
}

bool Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack is Empty" << endl;
        return false;
    }
    else
    {
        top--;
        return true;
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty" << endl;
        return false;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::isFull()
{
    return (top == MAX - 1);
}

void Stack::print()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    else
    {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

//* Extend Stack class to make SpecialStack

class SpecialStack : public Stack
{
    Stack min;

public:
    int pop();
    bool push(int x);
    int getMin();
};

bool SpecialStack::push(int x)
{
    if (isEmpty())
    {
        //* We're overriding push so for using parent method we need to use scope resolution
        Stack::push(x);
        min.push(x);
    }
    else
    {
        Stack::push(x);
        int y = min.peek();
        // if (x < y)
        // {
        //     min.push(x);
        // }
        // else
        // {
        //     min.push(y);
        // }
        //* Optimization : Push only when incoming is greater than equal to top
        if (x <= y)
        {
            min.push(x);
        }
    }
}

int SpecialStack::pop()
{
    // int x = Stack::peek();
    // Stack::pop();
    // min.pop();
    // return x;
    //* Optimization:  Push the popped element y back only if it is not equal to x
    int x = Stack::peek();
    Stack::pop();
    int y = min.peek();
    min.pop();
    if (y != x)
    {
        min.push(y);
    }
    return x;
}

int SpecialStack::getMin()
{
    int x = min.peek();
    return x;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin() << endl;
    cout << "pop " << s.pop() << endl;
    cout << s.getMin() << endl;
    s.print();
    return 0;
}