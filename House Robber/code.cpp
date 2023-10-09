class Solution {
public:
    
    int maxProfit(int currentIndex, int len, vector<int>&nums, vector<int>&memo)
    {
        //no-profit
        if(currentIndex >= len)
            return 0;
        
        if(memo[currentIndex] != -1)
            return memo[currentIndex];
        
        //explore possibilities
        int take = nums[currentIndex] + maxProfit(currentIndex+2,len,nums,memo);
        int notTake = maxProfit(currentIndex+1,len,nums,memo);
        
        memo[currentIndex] = max(take,notTake);
        return memo[currentIndex];
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>memo(n,-1);
        return maxProfit(0,n,nums,memo);
    }
};

// Time Complexity = O(2^n)
// Space Complexity = O(n)
