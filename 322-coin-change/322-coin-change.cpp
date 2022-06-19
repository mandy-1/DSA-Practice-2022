class Solution {
public:
    int solve(int idx,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(idx==0){
            if(amount%coins[0] == 0)return amount/coins[0];
            return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount]; 
        int notTake = 0+solve(idx-1,amount,coins,dp);
        int take=INT_MAX;
        if(coins[idx]<=amount){
            
            take= 1 + solve(idx,amount-coins[idx],coins,dp);
            }
        return dp[idx][amount]= min(notTake,take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       int ans = solve(coins.size()-1,amount,coins,dp);
       if(ans>=1e9)return -1;
        return ans;
        
    }
};