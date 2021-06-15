// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
// Problem Statement arr[] : {1, 2, 7}, To split array into to parts such that absolute(Sum2 - Sum1) = min
// Here Output = 4
// This problem is most similar to equal sum partition ques where Sum2 - Sum1 = 0, say S2 & S1
// S1, S2 belongs to [0, sum of all array elements(range)] // We found the extreme values of S1 & S2 ie when subset is empty and completely fill
// Here S1, S2 belongs to [0, 10] ie {1,2,3,4,5,6,7,8,9,10}
// Since S1 + S2 = range -> S2 = range - S1 -> Problem reduces to (Range - 2*S1) = min
// Assuming S2>S1 -> S1 < (Range/2) , to make overall positive difference
// Hence S1 belongs to [0, 5] ie {1,2,3,4,5} , Now we filter out the sums which are not possible to make with given array
// How to filter? Ans: by using subset sum problem for example sum = 4 will exist or not for given {1,2,7} array
// Hence S1 belongs to {1,2,3}
//   0  1 2 3 4 5 6 7 8 9 10  -> j(Sum)
// 0 T  F F F F F F F F F  F   
// 1 T
// 2 T
// 3 T  T T T F F F T T T  T   // This last row represents(smaller problems) when size of array is 3 & sum varies from 0 to 10
// i(n)
// We put the true T of the first half of this last row in a vector v


// code
boolean subsetSum(int arr[], int Range){

}

int min = INT_MAX;
for(int i=0; i<v.size(); i++){
    diff = min(diff, Range-2v[i]);
}

