//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sol(int idx,int prev,int N,int& k,vector<vector<vector<int>>>& dp){
        if(idx == k ){
            if(N==0)return 1;
            else return 0;
        }
        if(N<prev)return 0;
        if(dp[idx][N][prev] != -1)return dp[idx][N][prev];
        // cout<<idx<<" "<<prev<<" "<<N<<endl;
        int cnt=0;
        for(int i=prev;i<=N;i++){
            cnt += sol(idx+1,i,N-i,k,dp);
        }
        return dp[idx][N][prev] = cnt;
    }  
  
    int countWaystoDivide(int N, int K) {
        vector<vector<vector<int>>>dp(K+1,vector<vector<int>>(N+1,vector<int>(N+1,-1)));
        return sol(0,1,N,K,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends