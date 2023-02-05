//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int sol(int idx,vector<int>& a,int prev,vector<vector<int>>& dp){
      if(idx>=a.size())return 0;
      if(dp[idx][prev] != -1)return dp[idx][prev];
      int take=INT_MIN;
      int notTake=INT_MIN;
      
      if(prev<2){
          take = a[idx]+sol(idx+1,a,prev+1,dp);
      }
      notTake = sol(idx+1,a,0,dp);
        return dp[idx][prev] = max(take,notTake);
  }
  int findMaxSum(vector<int>& a){
      vector<vector<int>>dp(a.size(),vector<int>(3,-1));
      return sol(0,a,0,dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends