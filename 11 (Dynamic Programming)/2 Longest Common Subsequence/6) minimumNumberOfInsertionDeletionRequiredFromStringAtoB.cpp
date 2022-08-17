// https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/
// here insert and delete are there if replace is also there then it will become famous edit distance problem

// Problem Statement: Given two strings ‘str1’ and ‘str2’ of length m and n respectively. 
// The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2.
// It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
// Example: x = heap ; y = pea :- Insert "p" in start of heap & Delete "h" & other "p" of heap
// Hence O/P: Insertion = 1 ; Deletion = 2 ;

// First we indentify if it's a DP problem i) Choice ii) Optimal is asked (here minimum)
// Second we see if we can relate it with LCS i) Input has 2 strings ii) Optimal is asked
// "ea" = LCS of both
// str1 -> LCS -> str2 ie we convert via LCS
// heap -> ea (2 deletion) -> pea (1 insertion)

// Hence, No. of Deletion = m - LCS
//        No. of Insertion = n - LCS
// m,n are length of strings.



// GFG CODE

int LCS(string x, string y, int m, int n){
    int t[1001][1001];
    
    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int j=0; j<=n; ++j) t[0][j] = 0;
    
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[m][n];
}
int minOperations(string str1, string str2) { 
    // Your code goes here
    int m = str1.size();
    int n = str2.size();
    int lcs = LCS(str1, str2, m, n);
    
    return m + n - 2*(lcs);   
}
