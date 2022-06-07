https://leetcode.com/problems/find-the-winner-of-the-circular-game/

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
