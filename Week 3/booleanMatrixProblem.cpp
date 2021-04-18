// Google the topic for ques/problem statement
// Method 1
// We will do this in a temp matrix, coz doing it in original matrix will create confusion between old 1 and new 1's
// Time complexity = No. of 1's(say = x) * (Time taken to change to all 1s in that row or column) = O(x * (m+n)), In worst case x = m*n
// Space complexity = O(m*n) extra space

// Nethod 2
// Instead of temp matrix, in the original matrix instead of converting 0 to 1 mark them as -1 to keep a track, hence later convert all -1 to 1
// Space = O(1)
// Time is same = O(x *(m+n))
