//~ Linked List

//* A linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.

//* Unlike arrays, linked list elements are not stored at a contiguous location; the elements are linked using pointers. They include a series of connected nodes. Here, each node stores the data and the address of the next node.

//~ Advantages of Linked Lists over arrays:
//* Dynamic Array.
//* Ease of Insertion/Deletion.
//* Insertion at the beginning is a constant time operation and takes O(1) time, as compared to arrays where inserting an element at the beginning takes O(n) time,where n is the number of elements in the array.

//~ Drawbacks of Linked Lists:
//* Random access is not allowed. We have to access elements sequentially starting from the first node(head node). So we cannot do a binary search with linked lists efficiently with its default implementation.
//* Extra memory space for a pointer is required with each element of the list.
//* Not cache-friendly. Since array elements are contiguous locations, there is the locality of reference which is not there in the case of linked lists.
//* It takes a lot of time in traversing and changing the pointers.
//* Reverse traversing is not possible in singly linked lists.
//* It will be confusing when we work with pointers.
//* Direct access to an element is not possible in a linked list as in an array by index.
//* Searching for an element is costly and requires O(n) time complexity.
//* Sorting of linked lists is very complex and costly.
//* Appending an element to a linked list is a costly operation, and takes O(n) time, where n is the number of elements in the linked list, as compared to arrays that take O(1) time.

//~ Types of Linked Lists:
//* Simple Linked List – In this type of linked list, one can move or traverse the linked list in only one direction. where the next pointer of each node points to other nodes but the next pointer of the last node points to NULL. It is also called “Singly Linked List”.
//* Doubly Linked List – In this type of linked list, one can move or traverse the linked list in both directions (Forward and Backward)
//* Circular Linked List – In this type of linked list, the last node of the linked list contains the link of the first/head node of the linked list in its next pointer.
//* Doubly Circular Linked List – A Doubly Circular linked list or a circular two-way linked list is a more complex type of linked list that contains a pointer to the next as well as the previous node in the sequence. The difference between the doubly linked and circular doubly list is the same as that between a singly linked list and a circular linked list. The circular doubly linked list does not contain null in the previous field of the first node.
//* Header Linked List – A header linked list is a special type of linked list that contains a header node at the beginning of the list.

//~ Applications of Linked Lists
//* Linked Lists can be used to implement useful data structures like stacks and queues.
//* Linked Lists can be used to implement hash tables, each bucket of the hash table can be a linked list.
//* Linked Lists can be used to implement graphs (Adjacency List representation of graph).
//* Linked Lists can be used in a refined way in implementing different file systems in one form or another.