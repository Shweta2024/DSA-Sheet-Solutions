class Solution {
    public:
    
    int maxProfit(int currentRow, int currentCol, int n, vector<vector<int>>&points, vector<vector<int>>& memo)
    {
        if(currentRow == n-1)
            return points[currentRow][currentCol];
            
        if(memo[currentRow][currentCol] != -1)
            return memo[currentRow][currentCol];
        int ans = 0;
        //explore
        for(int col = 0; col < 3; col++)
        {
            if(col != currentCol)
            {
                int temp = points[currentRow][currentCol] + maxProfit(currentRow+1,col,n,points,memo);
                ans = max(ans,temp);
            }
        }
        memo[currentRow][currentCol] = ans;
        return memo[currentRow][currentCol];
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        vector<vector<int>>memo(n,vector<int>(3,-1));
        int a = maxProfit(0,0,n,points,memo);
        int b = maxProfit(0,1,n,points,memo);
        int c = maxProfit(0,2,n,points,memo);
        // cout<<a<<"-"<<b<<"-"<<c<<endl;
        return max(a,max(b,c));
    }
};

// Time Complexity = O(2^(n*3))
// Space Complexity = (n*3)
