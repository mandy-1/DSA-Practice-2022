class Solution {
public:
    int dp[21][1001];
    
    // targetSum(target,index) return no of ways to reach target from index
    int targetSum(vector<int> &nums, int target, int index){
        if(index == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        if(nums[index]<=target)
            return dp[index][target] = targetSum(nums,target-nums[index],index+1) + targetSum(nums,target,index+1);
        return dp[index][target] = targetSum(nums,target,index+1);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int diff) {
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        if((sum+diff)%2 != 0){
            return 0;
        }
        int target = (sum+diff)/2;
        if(target<0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        int ans = targetSum(nums,target,0);
        return ans;}};