http://graphics.stanford.edu/~seander/bithacks.html

https://dev.to/the_unconventional_coder/bit-manipulation-hacks-3n88


// Done from codencode playlist
// Overview
// 1. How to check if ith bit is set or not
// 2. How to set the ith bit
// 3. Left & Right Shift
// 4. Counting number of set bits in a number using right shift
// 5. XOR and its properties.


// LEFT SHIFT
// N = N<<2; // Means shift to left by 2 digits
// N = N<<i; // means shift to left by i digits
// N = N*(2*i) // means shift left by i digits (is same as above) coz 5 -> 50 -> 5*(10^1) in this example base is 10, in binary base is 2 so *2^i


// RIGHT SHIFT
// N = N>>2; // Means shift to right by 2 digits
// N = N>>i; // means shift to right by i digits
// N = N/(2*i) // means shift right by i digits (is same as above) coz 50 -> 5 -> 5/(10^1) in this example base is 10, in binary base is 2 so /2^i


// CHECKING FOR ITH SET BIT (VERY IMP)
// N = Number, i = index
// N = 12(1100), i = 0 -> ans = false
// N = 12(1100), i = 1 -> ans = true

// N = 12 (00001100), Say, to check at i = 3
// F = 1  (00000001)
// F = F<<3 (00001000)
// now we will do binary & of N and F(1 left shifted i places) if the resultant is 00000000 then ith bit is 0 else is 1

cin>>n>>i;
int f = 1;
f = f<<i;

int res = n & f;

if(res == 0) cout<<"false"<<endl;
else 
    cout<<"true";

// short code for ith bit is set or not
cin>>n>>i;
if(n&(1<<i)) return true;
else         return false;

// BITWISE XOR OPERATION // (2 bit are same ans 0, different then 1)
// Properties
// 0^A = A
// A^A = 0
// A^B^C = A^(B^C) = (A^B)^C = C^A^B


// ALL PAIR SUM XOR
// arr[2, 4, 1]
// (2+2)^(2+4)^(2+1)
// (4+2)^(4+4)^(4+1)
// (1+2)^(1+4)^(1+1) 
// 
// = (4)^(6)^(3)
//   (6)^(8)^(5)
//   (3)^(5)^(2) = 14
// Naive is using 2 for loops in n^2 time
// You can see that except the diagnal 4, 8, 5, every no is repeating twice hence will cancel out in XOR
// Hence we can do this in linear time by XOR of 2A1^2A2^2A3 ans


// TOTAL SUM OF ALL PAIR XOR
// https://youtu.be/7mDzRRug9Sg
// 5^9 = 12
// arr[5, 3, 9]
// 5^3 = 0110
// 5^9 = 1100
// 3^9 = 1010
// Total = 28
// Novice/Brute force approach

int res = 0;

for(int i = 0; i <= n; i++)
    for(int j = i+1; j <= n; j++)
        res+= arr[i]^arr[j];

// Better solution
// If there are x numbers with ith bit set & y numbers with ith bit as 0 then total no of pairs which would result in ith bit set = x*y
// Total sum of above ex => 0*(2^0)+2*(2^1)+2*(2^2)+2*(2^3) = 0 + 4 + 8 + 16 = 28

int main(){
    int arr[1001];
    int n, res = 0;

    cin >> n;
    for(int i=0; i<= n; i++)
        cin>>arr[i];
    
    for(int i=0; i<31; i++){ // assuming every no is a 32 bit no
        int cnt0 = 0, cnt1 = 0;

        for(int j=1; j<=n; j++){
            if(arr[j]&(1<<i))
                cnt1++;
            else
                cnt0++;
        }

        int p = cnt0 + cnt1;

        res += (1<<i)*p;  // 2^i * total no of pairs

    }
    cout<<res;
    return 0;
}

Bit Manipulation ke formulas ->
a | b = a ^ b + a & b
a ^ (a & b) = (a | b) ^ b
b ^ (a & b) = (a | b) ^ a
(a & b) ^ (a | b)  = a ^ b
Addition Properties:
a + b = a | b + a & b
a + b = a ^ b + 2(a & b)
Subtraction Properties
a - b = (a ^ (a & b)) - ((a | b) ^ a)
a - b = ((a | b) ^ b) - ((a | b) ^ a)
a - b = (a ^ (a & b)) - (b ^ (a & b))
a - b = ((a | b) ^ b) = (b ^ (a & b))
