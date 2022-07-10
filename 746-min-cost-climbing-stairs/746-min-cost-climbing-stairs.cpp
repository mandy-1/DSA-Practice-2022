class Solution {
public:
    int f(int i,vector<int> cost,vector<int>&dp){
        if(i>cost.size()-1)return 0 ;
        if(i==cost.size()-1)return cost[i];
        if(dp[i] != -1)return dp[i];
        int one = cost[i]+f(i+1,cost,dp);
        int two = cost[i]+f(i+2,cost,dp);
        return dp[i]= min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int first=f(0,cost,dp);
        int second=f(1,cost,dp);
        return min(first,second);
    }
};