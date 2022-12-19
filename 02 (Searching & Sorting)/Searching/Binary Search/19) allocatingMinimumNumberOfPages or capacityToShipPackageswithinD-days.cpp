https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

https://youtu.be/2JSQIhPcHQg  Aditya verma

Variation of this question is very common in interviews!!

Same variation in leetcode:

https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
isme days ko weights allot krne hai

To minimise the max number of pages student can read
or to minimise the max amount of laod on the converyer belt.

The array can be unsorted.
literally impossible to solve this kind of question if you have not solved it before.
Brute force is thinking of recursion.
How to apply "binary search" in this?

Related Problems For Practice :
Book Allocation Problem (GFG)
Aggressive cow (spoj)
Prata and roti (spoj)
EKO (spoj)
Google kickstart A Q-3 2020
+ Below Leetcode Problems
1482 Minimum Number of Days to Make m Bouquets
1283 Find the Smallest Divisor Given a Threshold
1231 Divide Chocolate
1011 Capacity To Ship Packages In N Days
875 Koko Eating Bananas
Minimize 
774 Max Distance to Gas Station
410 Split Array Largest Sum  (Exact same!!)
https://leetcode.com/problems/split-array-largest-sum/description/
Do refer other solutions of these problems. Like DP etc depending on time complexity.


Search leetcode:
Minimum Number of Days to Make m Bouquets
Find the Smallest Divisor Given a Threshold
Divide Chocolate
Koko Eating Bananas
Minimize Max Distance to Gas Station: Premium

Variations in languagesm essence is same.
Given the number of bags,
return the minimum capacity of each bag,
so that we can put items one by one into all bags.


//////////////////////////
10 20 30 40,, to divide among 2 students
I want to make partitions to make them continuous.
Ek student ko ek book toh deni hi hai.
So, start: minimum book pages that student has to read will be of sbse jada page wali book ie 40
And end: maximimum book pages that a student can read total - sbse kam page wali ie 90 

0............50...62...75......100  : value denotes max number of pages a student can read
        mid: student cannot read more than 50 pages.

If I chose s1: 10 20 (cannot chose 30) coz then > 50
Now I chose s2: 30 (cannot chose 40) coz>50
So, I need to increase the capacity ie move towards right side.

Basically in these type of binary search we find "range of our answers" and decide which direction to move.

I got a possible answer 75, store it.
Since I want to minimise this capacity then I will move towards left of it.

//
// yeh function isValid banana main baat hoti hai iske variations m changes hoti hai depending on problem statement, 
// learn this how to make isValid function.

// code

class Solution {
public:
    bool isValid(vector<int>& weights, int days, int mid){
        int curday = 1;
        int sum = 0;
        for(auto &weight: weights){
            sum = sum + weight;
            if(sum > mid){  // matlab max allowed pages se jada pages ham allot karne lage usko
                curday++;      // move to second day or second student
                sum = weight; // that particular weight jo excess kar dia tha
            }
            if(curday>days){
                return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // define the range of our ans(binary search on answer)

        int high = accumulate(weights.begin(), weights.end(), 0);  // high can be taken as sum of weights or sum of weights-lowest weight.
        if(days==1) return high;
        int low = 0;                                               // height weight among all the weights
        for(auto &weight: weights){
            if(weight>low) low = weight;
        }
        
        int res=-1; // to store possible answers
        // final state after this while loop will be: right(out of bound) left/mid
        while(low<=high){
            int mid = (low+high)>>1;  // mid is the max no of pages
            // I check if mid is suitable or not
            if(isValid(weights, days, mid)){
                res = mid;
                high = mid-1;         // in search of better minimum ans
            } 
            else low = mid+1;
        }
        return res;
    }
};

