Reverse a number/Count the number of digits etc

Input: 1123
Output: 3211

Input: 1300
Output: 31

int solve(int n){
    int ans = 0;

    while(n>0){
        int digit = n%10; // digit extraction
        ans = 10*ans+digit;
        n = n/10;
    }
    return ans;
}

The time complexity of the solution is O(digitsCount).

Better Solution to just return count of digits: 
Number of digits in N = log10(N) + 1.
Proof :- 10K-1 <= N < 10K
Therefore, the time complexity of this solution is O(1).

// Check palindrome
// Simply compare with the reverse number
   
// Armstrong Number
https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1

// This is also armstrong number you just have to play with the digits.
Approach: The idea is to first count number digits (or find order). 
Let the number of digits be n. 
For every digit r in input number x, compute rn. 
If sum of all such values is equal to n, then return true, else false.
