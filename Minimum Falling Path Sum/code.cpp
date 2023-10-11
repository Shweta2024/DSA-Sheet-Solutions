class Solution {
public:
    
    int minSum(int currentRow, int currentCol, int n, vector<vector<int>>&matrix, vector<vector<int>>&memo)
    {
        if(currentRow > n || currentCol > n || currentCol < 0)
            return 100000;
        
        if(currentRow == n)
            return matrix[currentRow][currentCol];
        
        if(memo[currentRow][currentCol] != -1)
            return memo[currentRow][currentCol];
        
        int leftDiagonal = matrix[currentRow][currentCol] + minSum(currentRow+1,currentCol-1,n,matrix,memo);
        int down = matrix[currentRow][currentCol] + minSum(currentRow+1,currentCol,n,matrix,memo);
        int rightDiagonal = matrix[currentRow][currentCol] + minSum(currentRow+1,currentCol+1,n,matrix,memo);
    
        memo[currentRow][currentCol] = min(down,min(leftDiagonal,rightDiagonal));
        return memo[currentRow][currentCol];
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>>memo(n,vector<int>(n,-1));
        
        int ans = 100000;
        for(int currentCol = 0; currentCol < n; currentCol++)
        {
            int temp = minSum(0,currentCol,n-1,matrix,memo);
            ans = min(ans,temp);
        }
        return ans;
    }
};
