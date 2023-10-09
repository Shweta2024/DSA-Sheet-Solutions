class Solution {
public:
    
    int totalWays(int currentIndex, int target, vector<int>&memo)
    {
        //valid path
        if(currentIndex == target)
            return 1;
        
        //invalid path
        if(currentIndex > target)
            return 0;
        
        if(memo[currentIndex] != -1)
            return memo[currentIndex];
        
        int oneJump = totalWays(currentIndex+1,target,memo);
        int twoJump = totalWays(currentIndex+2,target,memo);
        
        memo[currentIndex] = oneJump+twoJump;
        return memo[currentIndex];
    }
    
    int climbStairs(int n) 
    {
        vector<int>memo(n+1,-1);
        return totalWays(0,n,memo);
    }
};

//Time Complexity = O(2^n), since we are having two options for each of the stairs
//Space Complexity = O(n), since we are using memo
