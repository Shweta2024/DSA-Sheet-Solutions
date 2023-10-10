class Solution {
public:
    
    int totalWays(int currentRow, int currentCol, int m, int n, vector<vector<int>>&memo)
    {
        if(currentRow == m && currentCol == n)
            return 1; // valid
        
        if(currentRow > m || currentCol > n)
            return 0; // invalid
        
        if(memo[currentRow][currentCol] != -1)
            return memo[currentRow][currentCol];
        
        //explore
        int down = totalWays(currentRow+1,currentCol,m,n,memo);
        int right = totalWays(currentRow,currentCol+1,m,n,memo);
        
        memo[currentRow][currentCol] = down+right;
        return memo[currentRow][currentCol];
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return totalWays(0,0,m-1,n-1,memo);
    }
};

// Time Complexity = O(m*n)
// Space Complexity = O(m*n)
