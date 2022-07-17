class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
       int n=nums.size() ;
       vector<int>dp(n,1),dp2(n,1);
       
       for(int i=1;i<n;i++){
             for(int j=0;j<i;j++){
                   if(nums[i] > nums[j] && dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                   }
             }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                   if(nums[i] > nums[j]  && dp2[i]<dp2[j]+1){
                        dp2[i] = dp2[j]+1;
               }  
            }
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(dp[i] > 1 && dp2[i] > 1){
                maxi = max(dp[i]+dp2[i]-1,maxi);
            }         
        }
        
       return n-maxi; 
    }
};