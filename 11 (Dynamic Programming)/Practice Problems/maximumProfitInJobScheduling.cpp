https://leetcode.com/problems/maximum-profit-in-job-scheduling/


Asked in Slice
https://leetcode.com/discuss/interview-question/1125434/Swiggy-SDE-2-online-assessment-or-Hackerrank/886672 

JAVA solution by Kushagra Pathak:
Yet to understand:

import java.util.*;
class Solution{
    static long maxTaxiEarnings(int n, int[][] rides){
        Arrays.sort(rides, (a,b)->a[1]-b[1]);
        long[] earning  = new long[rides.length];
        earnings[0] = rides[0][1] - rides[0][0] + rides[0][2];
        for(int i=1; i<rides.length; i++){
            earnings[i] = rides[i][1] - rides[i][0] + rides[i][2];
            int low = 0;
            int high = i-1;
            int idx = -1;
            while(low<=high){
                int mid = (low+high)/2;
                if(rides[mid][1] < row[i][0]){
                    idx = mid;
                    low = mid+1;
                }
                else high = mid-1;
            }
            if(idx != -1){
                earnings[i] += earnings[idx];
            }
            earnings[i] = Math.max(earning[i-1], earning[i]);
        }
        return earnings[rides.length - 1];
    }

    public static void main(String[] args){
        Scanner ob = new Scanner(System.in);
        int n = ob.nextInt();
        int[][] rides = new int[n][3];
        for(int i=0; i<n; ++i) rides[i][0] = ob.nextInt();
        for(int i=0; i<n; ++i) rides[i][1] = ob.nextInt();
        for(int i=0; i<n; ++i) rides[i][2] = ob.nextInt();

        System.out.println(maxTaxiEarnings(n, rides));
    }
}

