class Solution {
    public:
    
    int minCost(int currentIndex, int target, int k, vector<int>&heights, vector<int>&memo)
    {
        if(currentIndex == target) 
            return 0;
            
        if(memo[currentIndex] != -1)
            return memo[currentIndex];
            
        int ans = 1000000;
        for(int index = currentIndex+1; index <= currentIndex+k && index <= target; index++)
        {
            int temp = abs(heights[currentIndex]-heights[index]) + minCost(index,target,k,heights,memo);
            ans = min(ans,temp);
        }
        memo[currentIndex] = ans;
        return memo[currentIndex];
    }
  
    int minimizeCost(vector<int>& height, int n, int k)
    {
        vector<int>memo(n,-1);
        return minCost(0,n-1,k,height,memo);
    }
};

// Time Complexity = O(k^n), since we have k options for each stage
// Space Complexity = O(n), since we are using memo
