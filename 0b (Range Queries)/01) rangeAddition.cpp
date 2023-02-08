https://www.geeksforgeeks.org/constant-time-range-add-operation-array/

https://www.lintcode.com/problem/903/description 

https://www.youtube.com/watch?v=-SDHYqxI-Hc (Good explanation of range addition)

Leetcode: Range addition problem is there (Premium)
https://leetcode.ca/all/370.html
Alternate: 
https://leetcode.com/problems/corporate-flight-bookings/description/



CRUX: O(N+k)
When a query to add V is given in range [a, b] we will add V to arr[a] and –V to arr[b+1] 
now if we want to get the actual values of the array we will convert the above array into prefix sum array. 

 [2, 5, 3] means: mujhe 3 add krna hai 2 se leke 5 tak : brute force toh yeh hai ki sabme manually add kar do O(n*k)
 Optimal:
 mai 2 mein 3 add kar dun ar 5+1 ie 6 mein 3 subtract kar du toh isse ky hoga jab mai prefix sum lunga toh 
 2 se 5 tak 3 add hota chala jaega ar aage 6 se leke nullify ho jaega.

Visuals: https://assets.leetcode.com/users/votrubac/image_1562473681.png


 class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for (auto &v : bookings) {
            res[v[0] - 1] += v[2];            // for 0 based indexing
            if (v[1] < n) res[v[1]] -= v[2];  // -1 +1  // 0 based indexing  // In bound rahe.
        }
        for (auto i = 1; i < n; ++i) res[i] += res[i - 1];
        return res;
    }
};

// Another view to understand
[first,last,seats], this could be assumed as 'seats' number of passengers are boarding at the 'first' stop and leaving at the 'last+1' stop.
https://leetcode.com/problems/corporate-flight-bookings/solutions/353616/another-view-explaination-easy-to-understand/

https://leetcode.com/problems/corporate-flight-bookings/solutions/2221703/c-prefix-sum-easy-to-understand-solution/
