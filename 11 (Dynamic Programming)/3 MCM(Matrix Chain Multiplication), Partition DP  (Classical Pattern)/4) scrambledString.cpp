// https://www.interviewbit.com/problems/scramble-string/

// Prblem statement
// Bird View:- Given 2 strings 'a' & 'b', if they both are srambled strings return True else False
// Scrambled String constraints
// 1. Breaking in Binary Tree
// 2. No child should be empty string
// 3. We may choose any non-leaf node and swap its two children. >=0 swaps

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of A = “great”:
 great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”. (one swap)

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”. (two swaps)

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.
"great" is also scrambled string of "great". (0 swaps)

// g|reat or gr|eart or gre|at or grea|t ie length 1, 2, 3 ... to be taken on one side
// So, i = 1 to n-1 (i = 0 would make empty string, not allowed)

// How to identify
// This is mcm because here also we are moving the breaking point.
// g|r|e|a|t

// How to approach

// How to breakdown (in 2 recursive cases)

// Base condition









