//~ What is Heap Data Structure?
//* A heap is a tree based data structure where the tree is a complete binary tree that maintains the property that either the children of a node are less than itself (max heap) or the children are greater than the node (min heap).

//~ Types of heaps:

//^ Max-Heap:
//* In this heap, the value of the root node must be the greatest among all its child nodes and the same thing must be done for its left and right sub-tree also.
//* The total number of comparisons required in the max heap is according to the height of the tree. The height of the complete binary tree is always logn; therefore, the time complexity would also be O(logN).

//^ Min-Heap:
//* In this heap, the value of the root node must be the smallest among all its child nodes and the same thing must be done for its left ans right sub-tree also.
//* The total number of comparisons required in the min heap is according to the height of the tree. The height of the complete binary tree is always logn; therefore, the time complexity would also be O(logn).

//~ Characteristics of Heap:

//* Heap has the following characteristics:
//* The system assigns a unique heap identifier to each heap within the activation group. The heap identifier for the default heap is always zero. A storage management-bindable API, called by a program or procedure, uses the heap identifier to identify the heap on which it is to act. The bindable API must run within the activation group that owns the heap.
//* The size of a heap is dynamically extended to satisfy allocation requests. The maximum size of the heap is (4GB – 512KB). This is the maximum heap size if the total number of allocations (at any one time) does not exceed 128 000.
//* The maximum size of any single allocation from a heap is limited to (16MB – 64KB).

//~ How is Binary Heap represented?

//* A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.

//* The root element will be at Arr[0].
//* The below table shows indices of other nodes for the ith node, i.e., Arr[i]:

//^ Arr[(i-1)/2]	Returns the parent node
//^ Arr[(2*i)+1]	Returns the left child node
//^ Arr[(2*i)+2]	Returns the right child node

//* The traversal method use to achieve Array representation is Level Order Traversal.

//~ Applications of Heaps:

//* Heap Sort: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.
//* Priority Queue: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(log N) time. Binomial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.
//* Graph Algorithms: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.
//* Many problems can be efficiently solved using Heaps. See following for example. a) K’th Largest Element in an array. b) Sort an almost sorted array/ c) Merge K Sorted Arrays.

//~ Advantages of Heap Data Structure:

//* Efficient insertion and deletion: The heap data structure allows efficient insertion and deletion of elements. When a new element is added to the heap, it is placed at the bottom of the heap and moved up to its correct position using the heapify operation. Similarly, when an element is removed from the heap, it is replaced by the bottom element, and the heap is restructured using the heapify operation.
//* Efficient priority queue: The heap data structure is commonly used to implement a priority queue, where the highest priority element is always at the top of the heap. The heap allows constant-time access to the highest priority element, making it an efficient data structure for implementing priority queues.
//* Guaranteed access to the maximum or minimum element: In a max-heap, the top element is always the maximum element, and in a min-heap, the top element is always the minimum element. This provides guaranteed access to the maximum or minimum element in the heap, making it useful in algorithms that require access to the extreme values.
//* Space efficiency: The heap data structure requires less memory compared to other data structures, such as linked lists or arrays, as it stores elements in a complete binary tree structure.
//* Heap-sort algorithm: The heap data structure forms the basis for the heap-sort algorithm, which is an efficient sorting algorithm that has a worst-case time complexity of O(n log n).

//~ Disadvantages of Heap Data Structure:

//* Lack of flexibility: The heap data structure is not very flexible, as it is designed to maintain a specific order of elements. This means that it may not be suitable for some applications that require more flexible data structures.
//* Not ideal for searching: While the heap data structure allows efficient access to the top element, it is not ideal for searching for a specific element in the heap. Searching for an element in a heap requires traversing the entire tree, which has a time complexity of O(n).
//* Not a stable data structure: The heap data structure is not a stable data structure, which means that the relative order of equal elements may not be preserved when the heap is constructed or modified.
//* Memory management: The heap data structure requires dynamic memory allocation, which can be a challenge in some systems with limited memory. In addition, managing the memory allocated to the heap can be complex and error-prone.
//* Complexity: While the heap data structure allows efficient insertion, deletion, and priority queue implementation, it has a worst-case time complexity of O(n log n), which may not be optimal for some applications that require faster algorithms.