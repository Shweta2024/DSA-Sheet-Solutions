class Solution {
public:
    
    int minSum(int currentRow, int currentCol, int targetRow, int targetCol, vector<vector<int>>&grid, 
               vector<vector<int>>& memo)
    {
        if(currentRow > targetRow || currentCol > targetCol)
            return 200000; // invalid path
        
        if(currentRow == targetRow && currentCol == targetCol)
            return grid[currentRow][currentCol]; // valid path
        
        if(memo[currentRow][currentCol] != -1)
            return memo[currentRow][currentCol];
        
        int down = grid[currentRow][currentCol] + minSum(currentRow+1,currentCol,targetRow,targetCol,grid,memo);
        int right = grid[currentRow][currentCol] + minSum(currentRow,currentCol+1,targetRow,targetCol,grid,memo);
        
        memo[currentRow][currentCol] = min(down,right);
        return memo[currentRow][currentCol];
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return minSum(0,0,m-1,n-1,grid,memo);
    }
};

// Time Complexity = O(m*n)
// Space Complexity = O(m*n)
