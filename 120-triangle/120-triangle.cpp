class Solution {
public:
    int solve(int n,int m, vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(n == dp.size()-1)return triangle[n][m];
        if(dp[n][m] != -1)return dp[n][m];
        int down =triangle[n][m]+solve(n+1,m,triangle,dp);
        int dig = triangle[n][m]+solve(n+1,m+1,triangle,dp);
        return dp[n][m] = min(down,dig);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int dig=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,dig);
            }
        }
        return dp[0][0];
    }
};