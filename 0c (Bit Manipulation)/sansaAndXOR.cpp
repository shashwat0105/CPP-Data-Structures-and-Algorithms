// https://www.hackerrank.com/challenges/sansa-and-xor/problem

// arr = [3, 4, 5]
// Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays, 
// followed by XOR-ing the values thus obtained. Determine this value. 

// (3)^(4)^(5)^(3^4)^(4^5)^(3^4^5) = 6 ans

// Always think in terms of ODD & EVEN while working with XOR (very imp)
// Frequency of an element is odd then resultant of their XOR will be that element only
// if even times then 0
// Here, 3 appears 3 times in subarrays (odd)
// Here, 4 appears 4 times in subarrays (even)
// Here, 5 appears 3 times in subarrays (odd)

// hence, net is 3^5 = 6 ans

// Formula
// No of subarrays ith element(i = index+1) appears in = (i)*(n-i+1)  // derived using permutation and computation

int main()
{
    lli t , n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++) cin>>ar[i];
 
        lli cnt;
        lli res = 0;
        for(lli i=1;i<=n;i++)
        {
            cnt = (i) * (n - i + 1);  // 1 based indexing is used here
            if(cnt % 2) res ^= ar[i]; // if the count of that no is odd then it will appear in XOR
        }
 
        cout<<res<<endl;
    }
}
 


// alternate soln (easy another observation)

int sansaXor(vector<int> arr) {

    int k=arr.size();
    if(k%2==0) return 0;

    int res=0;

    for(int i=0;i<k;i+=2)
        res=res^arr[i];

    return res;
} 