class Solution {
public:
    int solve(int n ,int m, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(n==0 && m==0)return grid[0][0];
        if(n<0 || m<0)return 1e9;
        if(dp[n][m] !=-1)return dp[n][m];
        int left=grid[n][m] + solve(n,m-1,grid,dp);
        int up=grid[n][m] + solve(n-1,m,grid,dp);
        
        return dp[n][m]= min(left,up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};