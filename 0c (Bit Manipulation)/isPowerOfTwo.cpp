// https://leetcode.com/problems/power-of-two/

// Method 1
// To check if an integer is power of 2 or not is to count the number of set bits which should be equal to 1

bool isPowerOfTwo(int n) {
        
        if(n<=0) return false; // leetcode doesn't provided constraints on n, so we needed to write this else error.
        int cnt = 0;
        
        while(n){
            cnt++;
            
            n = n&(n-1);
        }
        return cnt==1
    }

/// OR ///
bool isPowerOfTwo(int n) {
        
        if(n<=0) return false; // leetcode doesn't provided constraints on n, so we needed to write this else error.
        
        return (n&(n-1)==0); // coz it removes the last set bit, if there is only 1 set bit then it will be removed and become = 0
}
