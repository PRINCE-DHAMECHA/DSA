//~ Queue
//* A queue is a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order.

//* We define a queue to be a list in which all additions to the list are made at one end, and all deletions from the list are made at the other end.The element which is first pushed into the order, the delete operation is first performed on that.

//~ Types of Queue:

//* Input Restricted Queue: This is a simple queue. In this type of queue, the input can be taken from only one end but deletion can be done from any of the ends.
//* Output Restricted Queue: This is also a simple queue. In this type of queue, the input can be taken from both ends but deletion can be done from only one end.
//* Circular Queue: This is a special type of queue where the last position is connected back to the first position. Here also the operations are performed in FIFO order.
//* Double-Ended Queue (Dequeue): In a double-ended queue the insertion and deletion operations, both can be performed from both ends.
//* Priority Queue: A priority queue is a special queue where the elements are accessed based on the priority assigned to them.

//~ Basic Operations for Queue in Data Structure:

//* Enqueue() – Adds (or stores) an element to the end of the queue..
//* Dequeue() – Removal of elements from the queue.
//* Peek() or front()- Acquires the data element available at the front node of the queue without deleting it.
//* rear() – This operation returns the element at the rear end without removing it.
//* isFull() – Validates if the queue is full.
//* isNull() – Checks if the queue is empty.