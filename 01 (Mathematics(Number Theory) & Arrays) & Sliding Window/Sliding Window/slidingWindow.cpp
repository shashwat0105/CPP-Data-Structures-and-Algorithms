Array/string + subarray/substring + largest/minimum + k (window size)
=> sliding window can be applied.

Types:
1) Fixed: to maximise sum etc
2) Variable (window size is not given but asked)
Eg: largest window, smallest window subjected to a condition.
Can use map/list etc.

Problems:
Fixed
1) Max/Min subarray of size k
2) 1st -ve in every window of size k
3) Count of occurence of anagram
4) Max of all subarray of size k
5) Max of min for every window size

// // Template of fixed window problems:
j and i are done separately
while(j<n){
    calculation on j
    if( <k) j++
    if( ==k){
        1) find some ans from that calculation
        2) slide the window i++, j++
    }
}

Variable
1) Largest/Smallest subarray of sum k
2) Largest substring with k distinct characters
3) Length of largest substring with no repeating characters
4) Pick toy (Easy but long problem statement)
5) Minimum window substring (Hard and THE sliding windowp problem)
   Yeh kar li toh saari kar le jaoge.

// Template for variable size window:
while(j<size){
   calculations
   if(condition<k) j++
   else if(condition ==k){
      ans from calculation
      j++
   }
   else if(condition>k){
      while(condition>k){
         remove calculations for i
         i++
      }
      j++
   }
}

// Some template links to go through during revising.
https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/92007/sliding-window-algorithm-template-to-solve-all-the-leetcode-substring-search-problem/
https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/
https://leetcode.com/discuss/study-guide/1773891/Sliding-Window-Technique-and-Question-Bank
https://leetcode.com/tag/sliding-window/discuss/?currentPage=1&orderBy=most_votes&query=
