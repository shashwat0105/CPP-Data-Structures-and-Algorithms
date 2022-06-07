https://leetcode.com/problems/permutation-sequence/

// Brute force to start in interview:
// Generate all permutations using recursion, store it in a data structure, sort it. 
// Kth permutation will lie at k-1 th index. Given we are using 0 based indexing.
// TC = O(N!*N*NlogN) ; N! for recursion, N for deep copy, NlogN for sorting.

// Don't jump to optimal solution directly

// Optimal:
// Similar to finding the position of a word in a dictionary done in 12th class

https://youtu.be/wT7gcXLYoao

// {1,2,3,4}
// Like permutations beginning with 1 are 6, with 2 are 6, we divide it recursively to obtain our result.

// TC - O(N^2)
// SC - O(N)

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i=1; i<n; ++i){    // if fact is n then n-1 factorial is computed to find the size of a block
            fact = fact*i;
            numbers.push_back(i);  // and stored in an array
        }
        numbers.push_back(n);
        string ans = "";
        k = k-1;                   // to make in 0 based indexing,, say k = 17-1 
        while(true){
            ans = ans + to_string(numbers[k/fact]);    // after dividing and converting to a character add that number(in 0 based indexing) to our ans say 16/6 = 2 so {7,8,9,10} 0 1 2 ie 9 is added
            numbers.erase(numbers.begin()+k/fact);     // erase 9
            if(numbers.size()==0){                     // keep doing until the list is empty
                break;
            }
            k=k%fact;                     // next value of k
            fact = fact/numbers.size();   // next value of fact     
        }
        return ans;
    }
};

