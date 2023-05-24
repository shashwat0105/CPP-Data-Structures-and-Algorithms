https://leetcode.com/problems/find-the-winner-of-the-circular-game/

https://youtu.be/uCsD3ZGzMgE  (A cool video about this famous problem) for k=2 case only.

40 -> 39 -> 38 .... 1   (Player at 24th position stays alive)
// ie the problem is recursively defined.
// Hence, we will use IBH method

// We can use other DS to store the numbering of persons like circular list etc, but we can also do it by vector.
// For vector we can use modulo to come at the start of the vector ie for rotation.
 
class Solution {
public:
    void solve(vector<int> person, int k, int index, int &ans){   // coz yahi ans return karana hai so we use pass it by reference
        if(person.size()==1){
            ans = person[0];                                      // ie only 1 person is left whose numbering is stored at first position
            return;
        }
        
        // finding person to die
        index = (index+k)%person.size();
        person.erase(person.begin()+index);
        
        // calling for smaller input
        solve(person, k, index, ans);
        
        // No induction step coz jo bande ko nikala uska kuch karna nahi hai as we did in sorting to put it at the correct place
        return;
    }
    
    
    int findTheWinner(int n, int k) {
        vector<int> person;
        for(int i=1; i<=n; i++) person.push_back(i);  // inserting the numbering inside our array
        
        k--;                                          // to include the friend jisse counting start hogi
        int index = 0;                                // sword jiske hath m hogi ie the first person
        int ans = -1;
        
        solve(person, k, index, ans);
        return ans;
    }
};

// Iterative of above code (Abhi tak yeh best hai mere liye)
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        k--;
        int index=0;
        while(v.size()>1){
            index=(index+k)%v.size();
            v.erase(v.begin()+index);
        }
        return v[0];
    }
};

// Most optimised:
// Iterative: O(N) Time, O(1) space
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = (ans + k) % i;
        return ans + 1;
    }
};

// Another recursive code for same as above iterative version.

If last member remaining - return 1.
Recurse for remaining n - 1 members. Just findTheWinner(n-1, k) would mean that we are starting from 0. So, we adjust the new position by adding k - 1 (denotes that we skip k - 1 players) and modding with n for wrap-around. +1 in the below equation accounts for the index starting from 1 and not from 0.
So final recursive equation becomes - 1 + findTheWinner(n - 1, k) + k - 1) % n

class Solution {
public:
    int findTheWinner(int n, int k) {
        return (n == 1 ? 1 : 1 + (findTheWinner(n - 1, k) + k - 1) % n);
    }
};
