TC = O(m+n)

Terminologies used in this algo

Pattern: abcdabc

Prefix: a, ab, abc, abcd ... (Subset of pattern but should start from the beginning)

Idea of KMP: Is there any prefix repeated in other parts of the strings?

Examples:
P1: a b c d a b e a b f
    0 0 0 0 1 2 0 1 2 0

P2: a b c d e a b f a b c
    0 0 0 0 0 1 2 0 1 2 3

P3: a a a a b a a c d
    0 1 2 3 0 1 2 0 0

    


