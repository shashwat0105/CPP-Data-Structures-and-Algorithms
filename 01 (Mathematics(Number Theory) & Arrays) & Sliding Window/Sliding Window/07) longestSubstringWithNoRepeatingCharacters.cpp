https://leetcode.com/problems/longest-substring-without-repeating-characters/

// This ques is in other folder as well. Hence some other submissions as well.


// similar code as previous question.
// Map size is number of unique characters = size of window
// Instead of k here is size of window.

int lengthOfLongestSubstring(string s) {
    //variable sliding window
    int i=0,j=0;
    unordered_map<char,int>mp;
    int n = s.size();
    int max_size=0;
    
    while(j<n){
        //insert letter in map and keep count of frequency
        mp[s[j]]++;
          
/* NOTE 
(1)  window_size = j-i+1
(2)  unique_size = mp.size() , this tells no. of unique character in given string s every time
*/            
        
        if(mp.size() > j-i+1){    // this case is never possible tho
            j++;                  //in order to maximize find more unique character
        }
        
        else if(mp.size() == j-i+1){
            //candidate of answer
            max_size = max(max_size,j-i+1);
            j++;
        }
        
        else if(mp.size() < j-i+1)  {
            // p w w --> mp.size()==2 and j-i+1 = 2-0+1 = 3 
            
            //remove calculation for i 
            while(mp.size() < j-i+1){
                mp[s[i]]--;
                //if frequency of that character becomes 0 remove it
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;// go for next position
            }
            j++;
        }
    }
    return max_size;
}
