class Solution {
public:
    int f(int i,vector<int>& nums , int target , vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(i == nums.size() && target >0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int notPick = f(i+1,nums,target,dp);
        int pick = 0;
        if(nums[i]<=target){
            pick = f(0,nums,target-nums[i] , dp);
        }
        return dp[i][target] = (pick+notPick);
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return f(0,nums,target,dp);
    }
};