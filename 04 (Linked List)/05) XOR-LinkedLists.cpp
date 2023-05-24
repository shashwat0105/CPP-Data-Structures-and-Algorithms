XOR Linked Lists are Memory Efficient implementation of Doubly Linked Lists.

In the XOR linked list instead of storing actual memory addresses every node stores the XOR of addresses of previous and next nodes. ie reduce the space by half.

Ordinary Representation:
    Node A: prev = NULL, next = add(B)   // previous is NULL and next is address of B
    Node B: prev = add(A), next = add(C) // previous is address of A and next is address of C

XOR List Representation: Let us call the address variable in XOR representation as npx (XOR of next and previous)
    Node A: npx = 0 XOR add(B)          // bitwise XOR of zero and address of B
    Node B: npx = add(A) XOR add(C)     // bitwise XOR of address of A and address of C

// How to traverse:
XOR of add(B) and npx of C gives us the add(D). 
So we have the address of the next node. Similarly, we can traverse the list in a backward direction. 



