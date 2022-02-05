TC = O(m+n)

Terminologies used in this algo
String: abskdskdjssdjskjajckasxsabcdabc
Pattern: abcdabc

Prefix: a, ab, abc, abcd ... (Subset of pattern but should start from the beginning)

Idea of KMP: Is there any prefix repeated in other parts of the strings?

Examples: P1, P2... are example of patterns
P1: a b c d a b e a b f
pi  0 0 0 0 1 2 0 1 2 0

P2: a b c d e a b f a b c
pi  0 0 0 0 0 1 2 0 1 2 3

P3: a a a a b a a c d
pi  0 1 2 3 0 1 2 0 0


vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}    


