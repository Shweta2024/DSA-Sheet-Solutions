class Solution {
public:
    
    int maxProfit(int currentIndex, int n, vector<int>&nums, vector<int>& memo)
    {
        if(currentIndex > n)
            return 0;
        
        if(memo[currentIndex] != -1)
            return memo[currentIndex];
        
        //explore
        int take = nums[currentIndex] + maxProfit(currentIndex+2,n,nums,memo);
        int notTake = maxProfit(currentIndex+1,n,nums,memo);
        
        memo[currentIndex] = max(take,notTake);
        return memo[currentIndex];
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        
        vector<int>memo1(n+1,-1);
        vector<int>memo2(n+1,-1);
        return max(maxProfit(0,n-2,nums,memo1),maxProfit(1,n-1,nums,memo2));
    }
};

// Time Complexity = O(2^n)
// Space Complexity = O(n)
