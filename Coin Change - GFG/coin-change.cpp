//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int sol(int idx,int coins[],int& n,int sum,vector<vector<long long int>>& dp){
      if(sum==0)return 1;
      if(idx>=n && sum!=0)return 0;
      if(dp[idx][sum] != -1)return dp[idx][sum];
      long long int take=0;
      long long int notTake=0;
      if(coins[idx]<=sum){
          take=sol(idx,coins,n,sum-coins[idx],dp);
      }
      notTake = sol(idx+1,coins,n,sum,dp);
      return dp[idx][sum] = take+notTake;
  }
  
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        return sol(0,coins,N,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends