class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        int profit=0;
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=0;j<2;j++){
               
                if(j){
                    int take= -a[i] + dp[i+1][0];
                    int notTake = 0 + dp[i+1][1];
                    profit = max(take,notTake);
                }
                else{
                    int sell = a[i] + dp[i+1][1];
                    int notSell = 0 + dp[i+1][0];
                    profit = max(sell,notSell);
                }
                dp[i][j]= profit;
            }
        }
        return dp[0][1];
    }
};