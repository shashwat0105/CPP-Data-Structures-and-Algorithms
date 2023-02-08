https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

// Whenever we consider any number time[i] we can have 2 possibilities :

// 1) Number is divisible by 60.  
// 2) Number is not divisible by 60.

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        int n = time.size();
        vector<int> m(60,0);      // will store the count of remainders in that particular location in the array.
        
        for(int i=0; i<n; i++){
            int a = time[i] % 60;

            if(a==0){
                count+=m[0];      // for remainder 0 we want couterpart number to have remainder = 0 as well.
            }
            else {
                count+=m[60-a];   // a ==0 is handled separately because there is no location 60-0 is 60
            }
            m[a]++; 
        }
        return count;
    }
};


// If you want to avoid the case when a == 0
// Say time[i] = 240
// a = 240 % 60 = 0
// so, if we use b = (60 - a)%60; = (60-0) % 60 = 0 instead of just 60-a
// the extra % sign converts 60 back to 0

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        int n = time.size();
        vector<int> m(60,0);      
        
        for(int i=0; i<n; i++){
            int a = time[i] % 60;
            int b = (60-a) % 60;
            
            count += m[b];
            m[a]++; 
        }
        return count;
    }
};

// Same code
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        int n = time.size();
        vector<int> m(60, 0);
        for(auto t: time){  
            cnt += m[(60-(t%60))%60];
            m[t%60]++;;
        }
        return cnt;
    }
};


