Assignment 3: Right Leaning Red Black Tree

/* *****************************************************************************
 *  Describe how your printRange(const Key& lo, const Key& hi) method 
 *  in RLRB.cpp prints all the keys of the tree in the range low to hi.
 **************************************************************************** */

It makes use of recursion to print each key in the range
Case 1: If the node being examined is a null pointer, return from the function
Case 2: If the lower limit is less than the key of the current node, examine the left child recursively
Case 3: If the current node is within [lo, hi], print it
Case 4: If the upper limit is greater than the key of the current node, examine its right child recursively

/* *****************************************************************************
 *  The list of words in the dictionary is in sorted order and if you insert
 *  words in the same order in a vanilla version of BST, it will be created as 
 *  a degenerated tree. Does the RLRB tree solve this problem. If so, then how?
 *  Write your understanding.
 **************************************************************************** */

if (isRed(node->left) && !isRed(node->right)) node = rotateRight(node);
if (isRed(node->right) && isRed(node->right->right)) node = rotateLeft(node);
if (isRed(node->left) && isRed(node->right)) flipColors(node);

These three lines in the put() method are responsible for preventing a degenerate tree form forming.
They balance out the tree by making sure that the tree always obeys the restrictions of red-black trees:
■ Red links lean (right in this tree) left.
■ No node has two red links connected to it.
■ The tree has perfect black balance : every path from the root to a null link has the same number of black links.

eg)
1 2 3 4 5 insertion in standard bst:
1
 \
  2
   \
    3
     \
      4
       \
        5

1 2 3 4 5 insertion in red black tree:
Insert 1: Root node is black.
Insert 2: Red link to the right.
Insert 3: Causes a right-leaning violation; perform a left rotation:

    2 (Black)
   / \
  1   3 (Red)

Insert 4: Insert as a red link under 3. Still balanced.
Insert 5: Right-leaning violation at 3 triggers a rotation:

        2 (Black)
       / \
      1   4 (Black)
         / \
        3   5 (Red)


/* *****************************************************************************
 *  Known bugs / limitations.
 **************************************************************************** */

A copy/assignment constructor has not been implemented so tree can not be a return value from a function.
eg)
RightLeaningRedBlackBST<int, char> initTree();
The tree returned from this function will not be the same as the tree initialized within the function.
(Learned this the hard way when I tried to create a function that initialized the dictionary and returned it, leading to errors when using that tree :p) 

/* *****************************************************************************
 *  Describe any serious problems you encountered.                    
 **************************************************************************** */

Correctly handling the memory to prevent memory leaks was kind of tricky.
Verified memory safety with valgrind
valgrind terminal output for running test_RLRB.cpp:

$ valgrind bin/test_RLRB
==36375== Memcheck, a memory error detector
==36375== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==36375== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==36375== Command: bin/test_RLRB
==36375== 
(1, foo) (2, bar) (3, baz) (4, qux) (8, xyz) (11, abc) 
(8, xyz) (11, abc) 
(1, foo) (2, bar) (3, baz) (4, qux) 

(1, foo) (2, bar) (3, baz) (4, qux) (8, xyz) (11, abc) 
(2, bar) (1, foo) (4, qux) (3, baz) (8, xyz) (11, abc) 
(1, foo) (3, baz) (11, abc) (8, xyz) (4, qux) (2, bar) 
(2, bar) (1, foo) (4, qux) (3, baz) (8, xyz) (11, abc) 
All tests passed
==36375== 
==36375== HEAP SUMMARY:
==36375==     in use at exit: 0 bytes in 0 blocks
==36375==   total heap usage: 62 allocs, 62 frees, 77,116 bytes allocated
==36375== 
==36375== All heap blocks were freed -- no leaks are possible
==36375== 
==36375== For lists of detected and suppressed errors, rerun with: -s
==36375== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$

/* *****************************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **************************************************************************** */

 N/A

