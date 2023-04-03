https://leetcode.com/problems/k-th-symbol-in-grammar/
https://youtu.be/5P84A0YCo_Y (Aditya Verma)

N = 1   0
N = 2   0 1
N = 3   0 1 1 0
N = 4   0 1 1 0 1 0 0 1
N = 5:  0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
Observation of row 3 and 4
1 2 3 4
1 2 3 4 1' 2' 3' 4'  // ie first half of 4th row is same as 3rd row, while second half is the complement of 3rd row.
// here we can observe that length is getting twice in each row
// and elements before mid of nth row is equal to (n-1)th row
// and elements after mid of nth row is equals to !(n-1)th row elements.

// here we have to wisely reduce k, as n can be simply reduced by n-1

class Solution {
public:
    int kthGrammar(int n, int k) {
        int mid = (pow(2, n-1))/2;               // 2^(n-1) are the no of elements in nth row.
        if(n==1 || k==1) return 0;
        
        if(k<=mid) return kthGrammar(n-1, k);    // if k lies in the first half
        else return !kthGrammar(n-1, k-mid);     // else k lies in the second half.
    }
};

// Hint: Try to represent the current (N, K) in terms of some (N-1, prevK). What is prevK ?
// prevK is either k or k-mid say k is 7 then k-mid = 7-4 = 3 ie its previous was 3.

// Adding k = 1 improves the TC to O(logk).

// Other methods can be found in leetcode discuss of this ques.
          0
        0    1
      0  1  1  0
// observation by child nodes method is there as well.
// Another method is without recursion just by using value of K (SMORT)
