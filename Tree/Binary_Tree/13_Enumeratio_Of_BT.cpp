//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

//* A Binary Tree is labeled if every node is assigned a label and a Binary Tree is unlabelled if nodes are not assigned any label.

/* Below two are considered same unlabelled trees
    o                 o
  /   \             /   \
 o     o           o     o

Below two are considered different labelled trees
    A                 C
  /   \             /  \
 B     C           A    B  */

// How many different Unlabelled Binary Trees can be there with n nodes?

// For n  = 1, there is only one tree
//    o

// For n  = 2, there are two trees
//    o      o
//   /        \  
//  o          o

// For n  = 3, there are five trees
//     o      o            o          o      o
//    /        \         /  \        /        \
//   o          o       o    o      o         o
//  /            \                  \        /
// o              o                  o      o

//* The idea is to consider all possible pairs of counts for nodes in left and right subtrees and multiply the counts for a particular pair. Finally, add the results of all pairs.

// T(0) = 1  [There is only 1 empty tree]
// T(1) = 1
// T(2) = 2

// T(3) =  T(0)*T(2) + T(1)*T(1) + T(2)*T(0) = 1*2 + 1*1 + 2*1 = 5 // Try all combinations

// T(4) =  T(0)*T(3) + T(1)*T(2) + T(2)*T(1) + T(3)*T(0)=  1*5 + 1*2 + 2*1 + 5*1 =  14

// It's a series of catalan Numbers

//~ For unlabelled BT
//*  T(n) = (2n)! / (n+1)!n!

//? What about if tree is labelled?

//~ we can try all possible combinations which is n!
//* T(n) = [(2n)! / (n+1)!n!] * n!