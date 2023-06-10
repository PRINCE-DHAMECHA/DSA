//~ Applications of BST:
//* Graph algorithms: BSTs can be used to implement graph algorithms, such as in minimum spanning tree algorithms.
//* Priority Queues: BSTs can be used to implement priority queues, where the element with the highest priority is at the root of the tree, and elements with lower priority are stored in the subtrees.
//* Self-balancing binary search tree: BSTs can be used as a self-balancing data structures such as AVL tree and Red-black tree.
//* Data storage and retrieval: BSTs can be used to store and retrieve data quickly, such as in databases, where searching for a specific record can be done in logarithmic time.

//~ Advantages:
//* Fast search: Searching for a specific value in a BST has an average time complexity of O(log n), where n is the number of nodes in the tree. This is much faster than searching for an element in an array or linked list, which have a time complexity of O(n)
//* in the worst case.In - order traversal: BSTs can be traversed in-order, which visits the left subtree, the root, and the right subtree. This can be used to sort a dataset.

//~ Disadvantages:
//* Skewed trees: If a tree becomes skewed, the time complexity of search, insertion, and deletion operations will be O(n) instead of O(log n), which can make the tree inefficient.
//* Additional time required: Self-balancing trees require additional time to maintain balance during insertion and deletion operations.
//*  Efficiency: BSTs are not efficient for datasets with many duplicates as they will waste space.