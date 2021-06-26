// https://www.geeksforgeeks.org/print-shortest-common-supersequence/

// Given two strings X and Y, print the shortest string that has both X and Y as subsequences. 
// If multiple shortest supersequence exists, print any one of them.
// I/P -> x : 'acbcf' & y : 'abcdaf' 
// O/P -> 'acbcdaf'

// Input: X = "HELLO",  Y = "GEEK"
// Output: "GEHEKLLO" OR "GHEEKLLO" OR Any string that represents shortest supersequence of X and Y

// length of SCS is = m+n - LCS  (reasoned in SCS ques)

// Similar to print LCS ques

    
// LCS table for x & y
//         phi a  b   c   d   a   f
//          0  1  2   3   4   5   6  -> n(Size of string y)
// phi  0   0  0  0   0   0   0   0
//  a   1   0  1  1   1   1   1   1
//  c   2   0  1  1   2   2   2   2
//  b   3   0  1  2   2   2   2   2
//  c   4   0  1  2   3   3   3   3
//  f   5   0  1  2   3   3   4   4
// m(Size of string x)

// Printing SCS:- write common part once + write rest of the string
// While in LCS we used to write only the common part (ie which was equal)
// & If LCS touches any boundary :- "ac" & phi -> LCS = empty string nothing to print more
// But when u hit boundary in SCS :- "ac" & phi -> SCS = "ac" ie extra ac we have to print more

LCS(x, y, m, n)  // calling LCS and making table then we perform further
t[][]

int i = m;
int j = n;
string s = "";

while(i>0 && j>0){
    if(x[i-1]==y[j-1]){      // if the string elements are equal
        s.push_back(x[i-1]); // we push the element in string which matches here x[i-1] & y[j-1] are same so can push any
        i--;
        j--;
    }
    else{                           // if the string elements are not equal toh bhi mereko include krna hai ab 
        if(t[i][j-1] > t[i-1][j]){  // then we compare the two values of subproblem(diagnal) and move in the direction of maximum
            s.push_back(y[j-1]);
            j--;  // move to the left
        }
        else
            s.push_back(x[i-1]);
            i--;
    }
}

while(i>0){
    s.push_back(x[i-1]);
    i--;
}

while(j>0){
    s.push_back(y[j-1]);
}

reverse(s.begin(), s.end());
return s;


