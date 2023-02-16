//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1e9+7;
  long long sol(int h,vector<long long>& dp){
      if(h==0 || h==1)return 1;
      if(dp[h] != -1)return dp[h];
      return dp[h]=((sol(h-1,dp)%mod)*(2*sol(h-2,dp)%mod + sol(h-1,dp)%mod))%mod;
  }
    long long int countBT(int h) { 
        vector<long long >dp(h+1,-1);
        return sol(h,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends