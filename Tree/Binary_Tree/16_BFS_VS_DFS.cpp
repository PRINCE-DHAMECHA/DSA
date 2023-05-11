//~ BFS:
//* Level Order Traversal
//* Time:- O(n)
//* Space:- O(W)

//~ DFS:
//* Inorder, Preorder, Postorder
//* Time:- O(n)
//* Space:- O(h)

//& Extra space required for Level order traversal is likely to be more when tree is more balanced and extra space for Depth First Traversal is likely to be more when tree is less balanced.

//* The most important points is, BFS starts visiting nodes from root while DFS starts visiting nodes from leaves. So if our problem is to search something that is more likely to closer to root, we would prefer BFS. And if the target node is close to a leaf, we would prefer DFS.