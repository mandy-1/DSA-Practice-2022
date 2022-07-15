class Solution {
public:
    int f(int i,int last,vector<int>& nums ,vector<vector<int>>& dp){
        if(i == nums.size())return 0;
        if(dp[i][last+1] != -1)return dp[i][last+1];
        int notPick = f(i+1,last,nums ,dp);
        int pick=0;
        if( last == -1 || nums[last]<nums[i]){
            pick = 1 + f(i+1,i,nums,dp);
        }
        return dp[i][last+1] = max(pick , notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};