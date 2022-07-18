class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size(), maxi=0,ans=0;
        vector<int>dp(n,1),ct(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    ct[i] = ct[j];
                }
                else if(dp[i] == dp[j]+1 && nums[j] < nums[i]){
                    ct[i] += ct[j];
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                ans+=ct[i];
            }
        }
        return ans;
    }
};