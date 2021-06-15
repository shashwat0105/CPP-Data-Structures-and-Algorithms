// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. But a substring needs to be continuos. 
// Problem Statement:- x = abcdgh (length = n), y = abedfghr (length = m) :- Longest common subsequence is abcd -> length = 4 Ans, whereas longest common substring is ab -> length = 2
// While writing recursive solution 3 things to be taken care of :- (i) Base condition (ii) Choice Diagram (iii) Making Input -> Smaller

// Base condition :- Smallest valid input, here input are the two strings hence smallest valid length of string is 0 ie empty string.
// Hence LCS = 0, in base condition 

// Choice Diagram (See the screenshot too)
// (i) If the last string element matches shortening the string length -> n-1 & m-1  (ii) If the last element does not matches then we take 2 cases in which we shorten the string one at a time ie n-1, m & n, m-1  -> then we take thier max

int LCS(string x, string y, int n, int m){
    // base condition
    if(n==0 || m==0){
        return 0;
    }

    // choice diagram
    if(x[n-1] == y[n-1]){   // ie last element is common
        return 1 + LCS(x, y, n-1, m-1);  // Instead of value when the elements matches we add 1 (qki yahi toh chahiye hai for count of LCS)
    }
    else
        return max(LCS(x, y, n, m-1), LCS(x, y, n-1, m));
}



