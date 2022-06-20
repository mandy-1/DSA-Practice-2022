class Solution {
public:
    int solve(int idx,int tar,vector<int>&nums , vector<vector<int>>& dp){
        if(idx==0){
            if(nums[0]==0 && tar==0)return 2;
            if(tar==0 || nums[0]==tar)return 1;
            return 0;
        }
        if(dp[idx][tar] != -1)return dp[idx][tar];
        int notTake=solve(idx-1,tar,nums,dp);
        int take=0;
        if(tar>=nums[idx]){
            take=solve(idx-1,tar-nums[idx],nums,dp);
        }
        
        return dp[idx][tar]= take+notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int d) {
        int n=nums.size();
        int TotalSum=0;
        for(int i=0;i<n;i++){
            TotalSum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(((TotalSum-d)/2)+1,-1));
        if(TotalSum-d<0 || (TotalSum-d)%2)return false;
        return solve(n-1,(TotalSum-d)/2,nums,dp);
    }
};
