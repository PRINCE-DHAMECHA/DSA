//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

//~ Approach-1 : using Stack:
//* As we already know, recursion can also be implemented using stack. Here also we can use a stack to perform inorder traversal of a Binary Tree. Below is the algorithm for traversing a binary tree using stack.
//* Create an empty stack (say S).
//* Initialize the current node as root.
//* Push the current node to S and set current = current->left until current is NULL
//* If current is NULL and the stack is not empty then:
//* Pop the top item from the stack.
//* Print the popped item and set current = popped_item->right
//* Go to step 3.

//? In short we are pushing till left most element and after that we're last element and then went it's right side recursively but without recursion //Hypocrisy

void inOrderStack(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        //* Reach left most node of curr
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        // Leftmost node which is not visited
        cout << curr->val << " ";
        // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn
        curr = curr->right;
    }
}
//~ Approach-2 : Morris Traversal :-
//* We'll use thread to keep track of root
//* https://www.youtube.com/watch?v=80Zug6D1_r4
//* We'll make thread from rightmost guy of left subtree to root, So whenever we encounter it we know that we're done with left side and now we can print root and move on to right side

void inOrderMorris(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        //* We are at node which don't have left so just print it and move to right
        if (curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            //* Move to rightmost of left tree
            //* Also there's already thread then we break
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            //* When we reach there, Make a thread from rightmost to root
            //* after making thread move to left
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            //* When rightmost node has already a thread print int's value, Remove thread and go to right side
            else
            {
                prev->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    //* Constructed binary tree is
    //*             1
    //*           /   \
    //*         2      3
    //*       /  \
    //*     4     5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrderStack(root);
    cout << endl;
    inOrderMorris(root);

    return 0;
}