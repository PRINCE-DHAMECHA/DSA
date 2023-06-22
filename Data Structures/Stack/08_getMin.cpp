//~ Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must have a time and space complexity of O(1).

//* We define a variable minEle that stores the current minimum element in the stack. Now the interesting part is, how to handle the case when the minimum element is removed. To handle this, we push “2x – minEle” into the stack instead of x so that the previous minimum element can be retrieved using the current minEle and its value stored in the stack

//~ Push(x): Insert x at the top of the stack
//& If the stack is empty, insert x into the stack and make minEle equal to x.
//& If the stack is not empty, compare x with minEle. Two cases arise:
//& If x is greater than or equal to minEle, simply insert x.
//& If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x.

//~ Pop(): Removes an element from the top of the stack

//& Remove the element from the top. Let the removed element be y. Two cases arise:
//& If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
//& If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve the previous minimum from the current minimum and its value in the stack.

//? How does this works?
//* When the element to be inserted is less than minEle, we insert “2x – minEle”. The important thing to note is, that 2x – minEle will always be less than x i.e. new minEle
//* while popping out this element we will see that something unusual has happened as the popped element is less than the minEle. So we will be updating minEle.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class MyStack
{
    stack<int> s;
    int minEle;

public:
    int getMin();
    int peek();
    int pop();
    void push(int x);
};

int MyStack::getMin()
{
    if (s.empty())
    {
        cout << "Stack is Empty";
        exit(1);
    }
    else
    {
        return minEle;
    }
}

int MyStack::peek()
{
    if (s.empty())
    {
        cout << "Stack is Empty";
        exit(1);
    }
    else
    {
        int t = s.top();
        return t < minEle ? minEle : t;
    }
}

void MyStack::push(int x)
{
    if (s.empty())
    {
        minEle = x;
        s.push(x);
        return;
    }
    else if (x < minEle)
    {
        s.push((2 * x) - minEle);
        minEle = x;
    }
    else
    {
        s.push(x);
    }
}

int MyStack::pop()
{
    if (s.empty())
    {
        cout << "Stack is Empty";
        exit(1);
    }
    int t = s.top();
    s.pop();
    if (t < minEle)
    {
        int mini = minEle;
        minEle = 2 * minEle - t;
        return mini;
    }
    return t;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    MyStack s;
    s.push(3);
    s.push(5);
    s.push(2);
    cout << s.pop() << endl;
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    cout << s.pop() << endl;
    cout << s.getMin() << endl;
    s.pop();
    s.peek();
    return 0;
}