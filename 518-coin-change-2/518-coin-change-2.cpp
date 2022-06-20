class Solution {
public:
    int solve(int idx,int tar,vector<int>&coins ,vector<vector<int>>&dp){
        if(idx==0){
            if(tar%coins[0]==0 || tar==0)return 1;
            return 0;
        }
        if(dp[idx][tar] != -1)return dp[idx][tar];
        int notTake = solve(idx-1,tar,coins,dp);
        int take=0;
        if(tar>=coins[idx]){
            take=solve(idx,tar-coins[idx],coins,dp);
        }
        return dp[idx][tar]= take+notTake;
    }
    
    int change(int tar, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return solve(n-1,tar,coins,dp); 
    }
};