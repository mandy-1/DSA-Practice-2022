class Solution {
public:
  
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    profit = max(-a[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else{
                    profit = max(a[i] + dp[i+2][1], dp[i+1][0]);
                }
                dp[i][buy]=profit; 
                    }
        }
        return dp[0][1];
        
    }
};