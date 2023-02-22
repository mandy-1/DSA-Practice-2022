//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    long int sol(int n,vector<long int>&dp){
        if(n==1 || n==2)return n-1;
        if(dp[n] != -1)return dp[n];
        return dp[n]= ((n-1)*(sol(n-1,dp)%mod + sol(n-2,dp)%mod)%mod)%mod;
    }
    long int disarrange(int N){
        vector<long int>dp(N+1,-1);
        return sol(N,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends