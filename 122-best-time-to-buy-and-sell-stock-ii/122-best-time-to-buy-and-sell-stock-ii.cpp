class Solution {
public:
    int f(int i,int buy,vector<int>& a,vector<vector<int>>& dp){
        if(i==a.size()) return 0;
        if(dp[i][buy]!= -1)return dp[i][buy];
        int profit=0;
        if(buy){
            int take= -a[i] + f(i+1,0,a,dp);
            int notTake = 0 + f(i+1,1,a,dp);
            profit = max(take,notTake);
        }
        else{
            int sell = a[i] + f(i+1,1,a,dp);
            int notSell = 0 + f(i+1,0,a,dp);
            profit = max(sell,notSell);
        }
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& a) {
        vector<vector<int>>dp(a.size(),vector<int>(2,-1));
        return f(0,1,a,dp);
    }
};