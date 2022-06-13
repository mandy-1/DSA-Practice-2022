class Solution {
public:
int solve(int i,int j1,int j2,int n,int m, vector<vector<int>>& grid ,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int maxi= -1e8;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        for(int a=-1;a<2;a++){
            for(int b=-1;b<2;b++){
                int val=0;
                if(j1 == j2){
                    val= grid[i][j1];                
                }
                else{
                    val= grid[i][j1]+grid[i][j2];
                }
                 val +=solve(i+1,j1+a,j2+b,n,m,grid,dp);
                maxi = max(maxi, val);
             }
        }
        return dp[i][j1][j2] = maxi;
    }
       
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};