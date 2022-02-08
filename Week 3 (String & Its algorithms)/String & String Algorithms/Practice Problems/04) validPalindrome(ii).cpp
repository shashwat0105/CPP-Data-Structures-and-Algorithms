https://leetcode.com/problems/valid-palindrome-ii/

// Time complexity - O(N) 
// SC = O(1)

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);   // skip 1 element from left or from right (can delete atmost 1 character)
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};

// without making a palindrome checking function

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;

        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                //Removing Left
                int L1 = i+1, R1 = j;
                while(L1<=R1 && s[L1] == s[R1]){     // also we dont want to return false when char arent equal so we dont use if to check if they are equal.
                    ++L1;
                    --R1;
                    if(L1>=R1) return true;          // either is true then true
                }
                
                //Removing Right
                int L2 = i, R2 = j-1;
                while(L2<=R2 && s[L2] == s[R2]){
                    ++L2;
                    --R2;
                    if(L2>=R2) return true;        
                }

                return false;
            }
        }
        return true;
    }
};


////////////////////
Some learning
//Removing Left
// THIS DOESNT WORK
// int L1 = L+1, R1 = R;
// while(L1<=R1){
//     if(s[L1] == s[R1]){   // here we have to now do something about else they are not equal loop tab bhi run hoga     
//         ++L1;
//         --R1;
//     }
//     if(L1>=R1) return true;
// }

// THIS WORKS
// int LL = L+1, LR = R;
// while(LL<=LR && s[LL]==s[LR]) {++LL;--LR;}
// if(LL>=LR) return true;
