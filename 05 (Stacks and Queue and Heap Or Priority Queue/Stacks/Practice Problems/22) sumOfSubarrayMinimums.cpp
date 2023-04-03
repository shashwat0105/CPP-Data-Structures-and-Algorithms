https://leetcode.com/problems/sum-of-subarray-minimums/

// Acha sawal hai!

https://youtu.be/9-TXIVEXX2w (Fraz thodi galti hai)
https://www.youtube.com/watch?v=HRQB7-D2bi0   (Code story with MIK)

// Generate all subarrays O(N^3)
// Generate and find min on the way O(N^2)

// Acc to given constraints need to do in O(N)
// We will use concept of monotonic stack
// Stack ka intuition ese aya ki har element ka contribution nikal skte hai kitni subarrays mein using NSL and NSR

Ex: 2 9 7 8 3 4 6 1

NSL of 3 is 2
NSR of 3 is 1

So, 9 7 8 3 4 6, making subarray always having 3 in it.
Can chose starting point in 4 ways 9,7,8,3
Can chose the ending point in 3 ways 3, 4, 6
Hence total 4*3=12 subarrays will have min number as 3

Another Dry Run:
Idx: 0  1 2 3 
Arr: 3  1 2 4
NSL:-1 -1 1 2   (Indices qki count nikalna hai)
NSR: 1  4 4 4   (Indices)

Table:
No   #LS  #RS  Product
3    1    1     1  // No of element in left side = (0-(-1)) = 1
1    2    3     6  // ie esi 6 subarrays hai jisme 1 is minium elment
2    1    2     2
4    1    1     1
Add all = 3*1 + 1*6 + 2*2 + 4*1 = 17   Ans

CODE

class Solution {
public:
    vector<int> getNSL(vector<int> &arr, int n){
        vector<int> res(n);
        stack<int> st;

        for(int  i=0; i<n; ++i){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();  // yaha > kia
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int> &arr, int n){
        vector<int> res(n);
        stack<int> st;

        for(int  i=n-1; i>=0; --i){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();  // yaha >=
            if(st.empty()) res[i] = n;
            else res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        int M = 1e9+7;

        for(int i=0; i<n; ++i){
            long long ls = i - NSL[i];  // number of elements in left
            long long rs = NSR[i]-i;    // number of elements in right
            long long totalWays = ls*rs; // itne subarrays honge jinka minimum arr[i] hoga
            long long totalSum = arr[i]*totalWays;
            sum = (sum+totalSum)%M; 
        }
        return sum;
    }
};


// Corner case:s
>, >= ka chakkar?
Kayde se NSl k liye bhi >= hona chahiye tha but consider the case

[2,13,13,13,13,13,13,13,1]

if we dont handle the repeating case then the answer will be 1117 but the actual answer is 389. 
We have counted several array twice!!
ie iska NSL hoga: -1 0 1 2 3 4 5 6 -1 agar waha pe > use kia
either use >, >= or >=, > for NSL and NSR respectively(ek baar kahi bhi). As I want ki ek side se 13 ek hi baar count ho.
Jada dikkat ho value daal k dry run kar k dekh lena (padhne time maine dekh lia hai)
Yahi bas yaad rakhna hai baaki easy hai.

// Similar ques
https://leetcode.com/problems/maximum-subarray-min-product/
// Histogram ar is wale ques mein max nikalna hai toh baar baar count kr bhi lia toh dikkat nahi qki, lena toh max hai
// Isliye >= >= dono jagah.
