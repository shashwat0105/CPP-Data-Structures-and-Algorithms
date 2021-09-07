// And the sum of subsets must add to sum of the array, else the below approach wont work.

// Problem statement arr[] : {1, 1, 2, 3}, difference = 1  // these are different 1's
// O/P :- 3 -> {{1,2},{1,3}}, {{1,2},{1,3}}, {{1,1,2},{3}} = No. of pair of subsets whose difference of sum is 1 ie S2 - S1 = 1 
// S2 - S1 = diff -> (i)
// S2 + S1 = Sum of array -> (ii)
// Adding (i) & (ii)
// S2 = (diff + Sum of array)/2
// diff is given in ques, sum of array could be found
// Hence our problem is reduced to find no of subsets whose sum is (1+7)/2 = 4, which is nothing but count of subset sum problem(Wow)

int sum = diff + (Sum of array - diff)/2;

return countOfSubsetSum(arr, sum);

