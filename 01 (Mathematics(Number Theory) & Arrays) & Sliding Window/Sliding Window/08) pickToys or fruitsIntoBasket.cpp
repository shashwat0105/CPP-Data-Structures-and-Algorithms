Pick Toys same isme toys pick krne hai.

Length of longest subarray with exactly 2 unique characters .


https://leetcode.com/problems/fruit-into-baskets/

// If all the trees had just one type of fruit then ans would be count of that fruit.
// Else if >1 types of fruit are there we can at max and we will take exactly two unique fruits.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        // edge case
        if(n==1) return 1;
        unordered_map<int, int> m;
        int i=0, j= 0;
        int len=0;
        while(j<n){
            m[fruits[j]]++;
            if(m.size() < 2){
                j++;
            }
            else if(m.size()==2){  // I will find my ans
                len = max(len, j-i+1);
                j++;
            }
            else if(m.size()>2){
                while(m.size()>2){ // jab tak yeh condition invalid nahi ho jaati
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0) m.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        // edge case of unique is 1
        if(m.size()==1){
            auto it = m.begin();
            return it->second;
        }
        return len;
    }
};
