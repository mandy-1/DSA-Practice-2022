class Solution {
public:
    int f(int i,int j,vector<int>& nums , vector<vector<int>>& dp){
        if(i>j)return 0;
        int maxi=INT_MIN;
        if(dp[i][j] != -1)return dp[i][j];
        for(int k=i;k<=j;k++){
            maxi = max(maxi,nums[i-1]*nums[k]*nums[j+1]+f(i,k-                                1,nums,dp)+f(k+1,j,nums,dp));
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n-2,nums,dp);
    }
};