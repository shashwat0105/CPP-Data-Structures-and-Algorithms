https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

// Using a string instead of stack so that u dont need to reverse, as a string can also be accessed from the end

// Using extra space to store the occurence of last occured element.
// My mistaked thought process
// Also we just cannot use one flag variable(that I was thinking initially) instead of a vector or extra space
// Pichle ques mein seedha ek ek match hua nikal dia jabki yaha esa nahi hai

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string str;
        std::vector<int> counts;                            // agar yaha vector ki jagah ek flag variable bas use kia hota 
        for(auto& c : s){
            if(str.empty() || str.back() != c)  {
                str.push_back(c);
                counts.push_back(1);                        // chalo yaha tm flag=1 kar doge
            }
            else{
                str.push_back(c);
                counts.back() ++;
                if(counts.back()==k){
                    for(int i = counts.back() ; i > 0; i--)/{
                        str.pop_back();
                    }
                    counts.pop_back();                       // But yaha pe hame pata hona chahiye ki purane flag ki value kya thi so that aage aane wale element ka count mil sake.
                }
            }
        }
        return str;
    }
};

// Other method using pair of stack or vector 
// See stack is concept jisme apan last element ko access karte hai jaroori nahi hai ki stack use kare hi, faltu mein fr reverse bhi karna padega.

https://youtu.be/oANMk2_jxmU

// Syntax:
// If u want to add 'a' 5 times, and 'b' 2 times then instead of a loop 
// res.append(5, 'a');
// res.append(2, 'b');
// can be used

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;                  // st is a vector so stl of vector will be used 
        for(auto c: s){
            if(st.empty() || st.back().first!=c){
                st.push_back({c, 1});
            }
            else{ // if it gets matched
                st.back().second++;
                if(st.back().second==k){            // is If block ko else k bahar bhi likh sakte hai koi dikkat nahi hai
                    st.pop_back();                  // last element ko poora hata do (Isme ek hi element mein sab hai toh hatane mein loop ni lagega)
                }
            }
        }

        string ans;
        for(auto x: st){
            ans.append(x.second, x.first);         // phle ata hai uska count, fr ata hai jo element dalna hai
        }
        return ans;
    }
};

