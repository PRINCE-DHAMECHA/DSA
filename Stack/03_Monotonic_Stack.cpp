//~ Monotonic Stack
//* A monotonic stack is a stack data structure that is used to solve problems related to finding the next greater or smaller element in an array.

//* In a monotonic stack, the elements are pushed onto the stack in a way that the top element of the stack always satisfies a certain order.

//* One of the key benefits of using a monotonic stack is that it allows us to avoid nested loops and unnecessary comparisons, which can significantly reduce the time complexity of the algorithm.

//~ Monotonic Increasing Stack:
//* It is a stack in which the elements are in increasing order from the bottom to the top of the stack.
//* we should not have a smaller element at top of a bigger element.

//& Before pushing into the stack, POP all the elements till either of one condition fails:
//* Stack is not empty
//* Stack’s top is bigger than the element to be inserted.
//& Then push the element into the stack.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

stack<int> increasingStack(vector<int> v)
{
    stack<int> s;
    for (auto i : v)
    {
        while (!s.empty() && s.top() > i)
        {
            s.pop();
        }
        s.push(i);
    }
    return s;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> v = {1, 2, 3, 4, 5, 4, 2, 59, 54};
    increasingStack(v); //* 1 2 2 54

    return 0;
}