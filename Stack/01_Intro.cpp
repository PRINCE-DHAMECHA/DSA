//~ Stack

// * A stack is a linear data structure in which the insertion of a new element and removal of an existing element takes place at the same end represented as the top of the stack.

//* LIFO

//~ Basic Operations on Stack
//* push() to insert an element into the stack. O(1)
//* pop() to remove an element from the stack. O(1)
//* top() Returns the top element of the stack. O(1)
//* isEmpty() returns true if stack is empty else false. O(1)
//* size() returns the size of stack. O(1)

//~ Types of Stacks:

//* Fixed Size Stack: As the name suggests, a fixed size stack has a fixed size and cannot grow or shrink dynamically. If the stack is full and an attempt is made to add an element to it, an overflow error occurs. If the stack is empty and an attempt is made to remove an element from it, an underflow error occurs.
//* Dynamic Size Stack: A dynamic size stack can grow or shrink dynamically. When the stack is full, it automatically increases its size to accommodate the new element, and when the stack is empty, it decreases its size. This type of stack is implemented using a linked list, as it allows for easy resizing of the stack.

//~ Applications of the stack:

//* Infix to Postfix /Prefix conversion
//* Redo-undo features at many places like editors, photoshop.
//* Forward and backward features in web browsers
//* Used in many algorithms like Tower of Hanoi, tree traversals, stock span problems, and histogram problems.
//* Backtracking is one of the algorithm designing techniques. Some examples of backtracking are the Knight-Tour problem, N-Queen problem, find your way through a maze, and game-like chess or checkers in all these problems we dive into someway if that way is not efficient we come back to the previous state and go into some another path. To get back from a current state we need to store the previous state for that purpose we need a stack.
//* In Graph Algorithms like Topological Sorting and Strongly Connected Components
//* In Memory management, any modern computer uses a stack as the primary management for a running purpose. Each program that is running in a computer system has its own memory allocations
//* String reversal is also another application of stack. Here one by one each character gets inserted into the stack. So the first character of the string is on the bottom of the stack and the last element of a string is on the top of the stack. After Performing the pop operations on the stack we get a string in reverse order.
//* Stack also helps in implementing function call in computers. The last called function is always completed first.
