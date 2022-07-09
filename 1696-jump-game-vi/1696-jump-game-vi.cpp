class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size());  
        dp[nums.size()-1]=nums[nums.size()-1];
        priority_queue<pair<int,int>> maxh; 
        maxh.push({dp[nums.size()-1],nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
            while(maxh.size() && maxh.top().second>i+k) maxh.pop(); 
            dp[i]=maxh.top().first+nums[i]; 
            maxh.push({dp[i],i});
        }
        return dp[0];
    }
};