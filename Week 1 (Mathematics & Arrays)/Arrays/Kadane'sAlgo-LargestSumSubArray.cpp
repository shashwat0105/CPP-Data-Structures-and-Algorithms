// (Modified) Kadane's Algorithm

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};  // the max subarray is 2, 4, -3, 5, 2
    int best = 0, sum =0;
    for(int k=0; k< 8; k++){
        sum = max(arr[k], sum+arr[k]);
        best = max(best, sum);
    }
    cout<<best;
    return 0;
}

// another implementation is using if else can check