// https://youtu.be/DPiY9wFxGIw (Luv channel vid)
// Watch this video again

// BIT is an array whose elements store sum from certain to certain postions
// Bit :- 1, 2, 3, 4, 5.....12, 13  (1 based indexing, array has 0 based indexing)

// Sum(1,13) = bit[13] + bit[12] + bit[8]
// coz: bit[13] stores sum from 13 to 13, bit[12] stores sum from 9 to 12, bit[8] stores sum from 1 to 8

int sum(int i){
    int ans = 0;
    for( ; i>0; i-=(i&-i)){
        ans += bit[i];
    }
    return ans;
}

// everytime we are removing a bit, so from a no we can remove max log(i) bits
// Time complexity is O(logn)

// Sum of l to r =>  sum(r) - sum(l-1)

// Adding a value x in ith index not replacing it
// For replacing call update(i, x-a[i]); // ie add the difference ie u want to replace 4 with 6 which is same as adding 2

void update(int i, int x){
    for( ; i<=N; i+=(i&(-i))){
        bit[i]+=x;
    }
}

// Practice Problems
// https://youtu.be/NOykDuH1_OY






