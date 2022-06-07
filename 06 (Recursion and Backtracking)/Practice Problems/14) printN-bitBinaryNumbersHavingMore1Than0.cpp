https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1/

// Thought process is similar to previous ques

#1's >= #0's  (Legal Prefix)

Use wired headset to hear
https://youtu.be/U81n0UYtk98

Start mein 1 hi rakhna padega

Also,
Choice for 1 is always available (As seen from the recursive tree)
Choice for 0 is when no of 1 > no of 0 in the current state. (ie #1 used till now = 3, #0 used till now = 2, then both equal is also allowed ie we can still add a 0)


class Solution{
public:	
    vector<string> ans;
    void solve(int n, int ones, int zeroes, string op){     // ones, zeroes are no of 1's 0's used till now to fill n position.
        if(n==0){                             // all the n bits are filled
            ans.push_back(op);
            return;
        }
        
        solve(n-1, ones+1, zeroes, op+'1');    // adding 1s is always allowed
        
        if(ones>zeroes){
            solve(n-1, ones, zeroes+1, op+'0');
        }
        // return;
    }
    
	vector<string> NBitBinary(int N){
	    string op = "";
	    solve(N, 0, 0, op);
	    return ans;
	}
};


