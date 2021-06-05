// problem statement
// arr[] : {1, 5, 11, 5} :- Is it possible to split the array in two (equal or unequal) parts such that the sum of the two subsets is equal. 
// O/P = T/F :- True if such partition is possible else false

// Sum of P1 = S1 = S, Sum of P2 = S2 = S -> Sum of array = 2S which is even,then only it is possible to do equal partition
// In above case sum = 22, hence our ques reduces to if there exists any subset whose sum is 11 (Sum/2) {Subset Sum Problem}

// Code
// Finding array sum (in above example it is 22)
int sum = 0;
for(int i = 0; i < size; i++){
    sum = sum + arr[i];
}
if(sum%2 !=0){  // i.e. when sum of array is odd 
    return false;  
}
if(sum%n ==0){  // i.e. when sum of array is even
    return subsetSum(arr[], Sum/2, n)
}
