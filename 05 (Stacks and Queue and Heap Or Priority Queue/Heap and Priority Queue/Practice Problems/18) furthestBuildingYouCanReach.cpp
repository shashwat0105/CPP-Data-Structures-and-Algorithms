V GOOD PROBLEM

https://leetcode.com/problems/furthest-building-you-can-reach/

// If u use ladders first then bricks:

// MIN HEAP

We plan to use ladders for maximum height differences and bricks for others...
To keep track of maximum (r) differences, we use a min-heap...
If at any instance the size of min-heap becomes more than the number of ladders, we remove the top of our min-heap and subtract it from the number of bricks...
In doing so, we are ensuring that the largest r difference are covered by ladder, and the remaining are covered by brick...
If the bricks goes below 0, we know that we cannot travel further as we have utilised all our ladders (in form of heap) and our bricks as well...

(Here r is the number of ladders)

class Solution {
public:
// We plan to use ladders for maximum height differences and bricks for others...
// Method 1: Using ladders first then bricks.
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq; // to hold 'k' highest climbs
        for(int i=1; i<n; ++i){
            int jumpHeight = heights[i]-heights[i-1];
            if(jumpHeight<=0) continue;
            pq.push(jumpHeight);         // abhi tak ladder use kar skte hai
            // ladder khatam ho gaye, kya kisi ladder ko brick se replace kr skte hai ab(optimise my ladder use)
            // mtlb mai replace kr hi de rha hu, chahe sbse chote ko brick se bhar do ya ladder se farq ni padega
            if(pq.size()>ladders){       
                bricks -= pq.top();      // jo top m store tha usko brick se kr do
                pq.pop();
            }
            if(bricks<0) return i-1;   
        }
        return n-1;
    }
};


// If u use all the bricks first, then ladders
We try to use all bricks first, storing elevations in the priority queue. When we do not have enough bricks, we replace some bricks with a ladder. 
We need to trade the largest number of bricks - which is the highest elevation on the top of the priority queue.

class Solution {
public:
// We plan to use ladders for maximum height differences and bricks for others...
// Jab bricks exhaust honge tab 
// Method 2: Using bricks first then ladders.
    int furthestBuilding(vector<int>& hs, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 1; i < hs.size(); ++i) {
            int d = hs[i] - hs[i - 1];
            if (d > 0) {
                pq.push(d);
                bricks -= d;
                if (bricks < 0) {
                    --ladders;
                    bricks += pq.top();
                    pq.pop();
                    if (bricks < 0 || ladders < 0)
                        return i - 1;

                }
            }
        }
        return hs.size() - 1;
    }  
};

Some soln
https://leetcode.com/problems/furthest-building-you-can-reach/solutions/1177210/easy-solution-w-clear-explanation-comments-priority-queue-multiset/
