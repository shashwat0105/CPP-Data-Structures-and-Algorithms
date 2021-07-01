// COUNTING NUMBER OF SET BITS
// https://leetcode.com/problems/number-of-1-bits/
// N = 12(1100) : Output = 2 
// N = 13(1101) : Output = 3
// Method 1
// We will perform right shift and & operation with 1 to check for no of set bits
// N&1 -> 00001100 & 00000001 = 0 ie 0th place doesnt has 1, then we right shift by 1 and again do & operation
// TC = O(logn)

cin>>n;
int cnt = 0;
while(n>0){
    if((n&1)>0) cnt++;

    n = n>>1;
}
cout<<cnt;

// Method 2, observation method (Dry run this u will get the ans)
cin>>n;
int cnt = 0;
while(n>0){ // runs as many times as there are set bits
    cnt++;

    n = n&(n-1); // in this operation we are removing the righmost set bit
}
return cnt;