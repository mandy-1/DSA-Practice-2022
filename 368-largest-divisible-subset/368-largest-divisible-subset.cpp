class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size() , maxi =1 , index=0;
        vector<int>dp(n,1),hash(n);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                index = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[index]);
        while(hash[index] != index){
            index = hash[index];
            ans.push_back(nums[index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};