class Solution {
public:
    bool solve(int idx,int k,vector<int>& nums,vector<vector<int>>& dp){
        if(k==0)return true;
        if(idx==0)return (nums[0]==k);
        if(dp[idx][k] != -1)return dp[idx][k];
        bool notTake=solve(idx-1,k,nums,dp);
        bool take=false;
        if(nums[idx]<=k){
            take=solve(idx-1,k-nums[idx],nums,dp);
        }
        return dp[idx][k] = (take or notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0)return false;
        int k=sum/2;
        
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(n-1,k,nums,dp);
    }
};