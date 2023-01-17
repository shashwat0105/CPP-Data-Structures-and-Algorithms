https://leetcode.com/tag/prefix-sum/discuss/2719912/Prefix-sum-study-summary

// Official solution
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/solutions/2773805/sum-of-all-odd-length-subarrays/

// Not an Easy question ~ Lee

// Brute force O(n^3)

O(n^2)
// BY keeping a running subarray sum:

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // Brute Force O(n^2)
        long ans = 0;
        int n = arr.size();
        for(int i=0; i<n; ++i){
            long tmp = arr[i];
            ans+=arr[i];  //INDIVIDUAL ELEMENT LENGTH IS 1 SO ITS ODD.
            for(int j=i+1; j<n; ++j){
                tmp+=arr[j];
                if((j-i+1)%2) ans+=tmp;  // length becomes oddd
            }
        }
        return ans;
    }
};

/*
ARR=[1,4,2,5,3]
FOR I=0;
    j=1-n
    when j=1
    (1-0+1)==2 .....EVEN SO SKIPPED BUT WE ADD IT TO tmp as we need SUBARRAY(not subsequence) of odd length sum
    when j=2
    (2-0+1)==3 ..... ODD LENGTH so tmp gets added to summa.. HERE WE ADDED [1,4,2]
    .
    .
    when j=4
    (4-0+1)==5... ODD LENGTH so tmp it gets added to summa.. HERE WE ADDED [1,4,2,5,3]
*/

// Some other O(n^2) coding styles:

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = int(arr.size()), answer = 0;

        
        for (int left = 0; left < n; ++left) {
            int currentSum = 0; 
            for (int right = left; right < n; ++right) {
                currentSum += arr[right];
                answer += (right - left + 1) % 2 == 1 ? currentSum : 0;
            }
        }
        return answer;
    }
};
/////////
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
     int res = 0;
     for(int i = 0; i < arr.length; i++){
         int sum = 0;
         for(int j = i; j < arr.length; j++){
            sum += arr[j];
            if(i == j) res += sum;
            else if((j-i)%2 == 0){
                 res += sum;
             }
         }
     }  
        return res;
    }
}

// MOST OPTIMISED
Check the occurrence of each index
Instead of finding all odd-length subarrays, we can count the number of occurrences of each integer in all odd-length subarrays. 
For example, if arr[i] has appeared k times, it contributes to the total sum by arr[i] * k.

Some videos when revising to watch
https://www.youtube.com/watch?v=LSFcmgq0HYY

https://www.youtube.com/watch?v=J5IIH35EBVE


No. of even subarrays = Total/2
No. of odd subarrays = (Total+1)/2
Total subarrays can be found by considering an element and taking all subarrays to its left and right.
Subarrays to the left = i+1
Subarrays to the right = n-i
We then add 1 i.e (i+1 * n-i )+1 to include the entire array as the subarray.
And that is done for each element from i=0 to i=arr.size()-1
And finally the sum is returned.


// Thode ar discuss
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/solutions/854304/c-o-n-single-line-logic/
Ceil wgyra ka comment/dry run dekh lena
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/solutions/867779/java-o-n-time-with-video-explanation/
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/solutions/854184/java-c-python-o-n-time-o-1-space/
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/solutions/980310/Dew-It-or-O(n)-1-pass-or-(Almost)-No-math/


Optimise code:

int sumOddLengthSubarrays(vector<int>& A) {
    int res = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
        res += ((i + 1) * (n - i) + 1) / 2 * A[i];
    }
    return res;
}