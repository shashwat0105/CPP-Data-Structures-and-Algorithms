// https://www.geeksforgeeks.org/printing-longest-common-subsequence/
// Printing LCS for input Sequences x = “acbcf” (m = 5) and y = “abcdaf” (n = 6) O/P is “abcf” string instead of int = 4

// How exactly LCS works:- 
// t[5+1][6+1] = t[6][7]

//         phi a  b   c   d   a   f
//          0  1  2   3   4   5   6  -> n(Size of string y)
// phi  0   0  0  0   0   0   0   0
//  a   1   0  1  1   1   1   1   1
//  c   2   0  1  1   2   2   2   2
//  b   3   0  1  2   2   2   2   2
//  c   4   0  1  2   3   3   3   3
//  f   5   0  1  2   3   3   4   4
// m(Size of string x)

// table filling(zoom out sample) (looking the diagnals is easy)
//      a  b
//  c   5
//  b      6(5+1) will be filled here coz b = b 
//
//      a   f
//  c   2   4
//  b   3   4(maximum of 3 & 4) will be filled here coz b != f
//

// Now we move backward from bottom right corner until we hit first row or column 4 -> 3 -> 3... depending upon the two elements are equal or not. Hence we will get "fcha" as string then we reverse it
// See the Screenshot
// if equal i, j -> i--, j-- & store the LCS alphabet

// if not equal max(i-1, j  ,, i,j-1)

LCS(x, y, m, n)
t[][]

int i = m;
int j = n;
string s = "";

while(i>0 && j>0){
    if(x[i-1]==y[j-1]){      // if the string elements are equal
        s.push_back(a[i-1]); // we push the element in string which matches
        i--;
        j--;
    }
    else{                           // if the string elements are not equal
        if(t[i][j-1] > t[i-1][j]){  // then we compare the two values of subproblem(diagnal) and move in the direction of maximum
            j--;  // move to the left
        }
        else
            i--;
    }
}

reverse(s.begin(), s.end());
return s;


// other sugestions
// Just a minor suggestion which wont make much of a difference but the reverse part for getting the LCS isn't required. 
// If we know the length of the sequence, we can just create a char array of length = lcs and start from the rightmost end/index
// of the char array and copy the characters which match accordingly. 
// we missed one case here
// Suppose a[ i-1 ] != b[ j - 1 ]
// and if ( t[ i ][ j-1 ] == t[ i-1 ][ j ] ) 
// what next operation shall we perform? This case can come if you have more than 1 LCS




