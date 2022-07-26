class Solution {
public:
    // int f(int i,int k,vector<int>& arr,vector<int>& dp){
    //     int n=arr.size();
    //     if(i==n)return 0;
    //     if(dp[i] != -1)return dp[i];
    //     int len=0,maxi=INT_MIN,globalMax=INT_MIN;
    //     for(int j=i;j< min(i+k,n) ;j++){
    //         len++;
    //         maxi = max(maxi,arr[j]);
    //         int sum=len*maxi+f(j+1,k,arr,dp);
    //         globalMax = max(globalMax,sum);
    //     }
    //     return dp[i] = globalMax;
    // }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
                 int len=0,maxi=INT_MIN,globalMax=INT_MIN;
                    for(int j=i;j< min(i+k,n) ;j++){
                        len++;
                        maxi = max(maxi,arr[j]);
                        int sum=len*maxi+dp[j+1];
                        globalMax = max(globalMax,sum);
                    }
            dp[i]=globalMax;
        }
        return dp[0];
    }
};