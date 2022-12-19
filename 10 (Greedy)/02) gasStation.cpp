https://leetcode.com/problems/gas-station/description/

Invalid movement:
Fuel in the tank < Distance or cost required to move.
Gas[i] < Cost[i] then that indexes we cannot start from ie not our ans.

https://youtu.be/xmJZSYSvgfE

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0;
        int cur_surplus = 0;
        int position = 0;

        for(int i=0; i<n; ++i){
            total_surplus += gas[i]-cost[i];
            cur_surplus += gas[i]-cost[i];

            if(cur_surplus<0){                  // need to reset our starting position
                cur_surplus = 0;
                position = i+1;
            }
        }
        return (total_surplus<0)?-1:position;  // >=0 then position else -1
    }
};

