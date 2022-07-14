class Solution {
public:
   int f(int i,int buy,vector<int>& a, vector<vector<vector<int>>>& dp , int count){
       if(count ==2) return 0;
       if(i==a.size()) return 0;
       
        if(dp[i][buy][count]!= -1)return dp[i][buy][count];
        int profit=0;
        if(buy){
            profit = max(-a[i] + f(i+1,0,a,dp,count),0 + f(i+1,1,a,dp,count));
        }
        else{
            profit = max(a[i] + f(i+1,1,a,dp , count+1),0 + f(i+1,0,a,dp , count));
        }
        return dp[i][buy][count] = profit;
    }
    int maxProfit(vector<int>& a) {
        vector<vector<vector<int>>>dp(a.size() ,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,a,dp,0);
    }
};