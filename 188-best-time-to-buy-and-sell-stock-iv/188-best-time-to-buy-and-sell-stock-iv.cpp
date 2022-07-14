class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
                        int take = -prices[idx] + dp[idx+1][0][cap];

                        
                        int notTake = 0 + dp[idx+1][1][cap];

                        dp[idx][buy][cap] = max(take,notTake);
                    }
                    else{
                        int sell = prices[idx] + dp[idx+1][1][cap-1];

                        int notSell = 0 + dp[idx+1][0][cap];
                        
                        dp[idx][buy][cap] = max(sell,notSell);
                    }
                }
            }
        }
        
        return dp[0][1][k];        
    }
};