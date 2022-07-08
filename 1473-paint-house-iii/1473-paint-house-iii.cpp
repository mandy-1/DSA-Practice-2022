class Solution {
public:
    int f(vector<int>& houses, vector<vector<int>>& cost,int i,int lc,int t,int n,int m,vector<vector<vector<int>>> &dp){
        if(i>=m || t<0){
            if(t==0) return t;
            return 1e9;
        }
        if(houses[i]!=0) return f(houses,cost,i+1,houses[i],t-(lc!=houses[i]),n,m,dp);
        if(dp[i][t][lc]!=-1) return dp[i][t][lc];
        int r=1e9;
        for(int c=1;c<=n;c++){
            r=min(r,cost[i][c-1]+f(houses,cost,i+1,c,t-(lc!=c),n,m,dp));
        }
        return dp[i][t][lc]=r;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (m+1,vector<int>(n+1,-1)));
        return f(houses,cost,0,0,target,n,m,dp)>=1e9 ? -1 : f(houses,cost,0,0,target,n,m,dp);
    }
};