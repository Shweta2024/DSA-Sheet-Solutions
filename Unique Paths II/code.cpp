class Solution {
public:
    
    int totalWays(int currentRow, int currentCol, int m, int n, vector<vector<int>>&memo, vector<vector<int>>& grid)
    {   
        if(currentRow > m || currentCol > n || grid[currentRow][currentCol] == 1)
            return 0;
        
        if(currentRow == m && currentCol == n)
            return 1;
        
        if(memo[currentRow][currentCol] != -1)
            return memo[currentRow][currentCol];
        
        int down = totalWays(currentRow+1,currentCol,m,n,memo,grid);
        int right = totalWays(currentRow,currentCol+1,m,n,memo,grid);
        
        memo[currentRow][currentCol] = down+right;
        return memo[currentRow][currentCol];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return totalWays(0,0,m-1,n-1,memo,obstacleGrid);
    }
};
