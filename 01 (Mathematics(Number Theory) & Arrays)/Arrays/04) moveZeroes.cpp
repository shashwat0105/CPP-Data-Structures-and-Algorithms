https://leetcode.com/problems/move-zeroes/

https://youtu.be/mgzcjQ1x9Mw


 void moveZeroes(vector<int>& nums) {
    int j=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!=0){
            nums[j] = nums[i];
            j++;
        }     
    }
    while(j<nums.size()){             // filling 0 in remaining places
        nums[j]=0;
        j++;
    }
}
