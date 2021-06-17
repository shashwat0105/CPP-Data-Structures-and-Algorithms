// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// x = abcde, y = abfce -> Common substrings -> ab, c, e -> longest is ab -> length = 2 Ans
// ie it should be continuos, this is different from LCS
// Jaha bhi match na kare waha pe length = 0 kar dena hai ie fr se shuru se start


int LCSubStr(string x, string y, int m, int n){

    int t[m+1][n+1];
    int result = 0; // (code variation) To store length of the longest common substring

    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n; j++){
            // base condition(Initialisation)
            if(i==0 || j==0){
                t[i][j] = 0;
            }

            // choice diagram
            if(x[i-1] == y[j-1]){   // ie last element matches
                t[i][j] = 1 + t[i-1][j-1];  // Instead of value when the elements matches we add 1 (qki yahi toh chahiye hai for count of LCS)
                result = max(result, t[i][j]); // (code variation)
            }
            else // when the elements does not match
                t[i][j] = 0;  // (code variation)no max nothing, if it is not equal then make it 0
            }
    }

    return result; // (code variation) we have to return the max value in the matrix and not t[m][n]. Cuz substring can exist anywhere in between. 
}




