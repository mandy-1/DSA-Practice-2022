//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int sol(int idx,int* a,int& n,int prev,vector<vector<int>>& dp){
        if(idx>=n)return 0;
        if(dp[idx][prev+1] != -1)return dp[idx][prev+1];
        int n1=INT_MIN;
        int n2=INT_MIN;
        if(prev == -1 || abs(a[prev]-a[idx]) == 1){
            n1 = 1+sol(idx+1,a,n,idx,dp);
        }
        n2= sol(idx+1,a,n,prev,dp);
        return dp[idx][prev+1] = max(n1,n2);
    }
    int longestSubsequence(int N, int A[])
    {
        vector<vector<int>> dp(N,vector<int>(N+1,-1));
        return sol(0,A,N,-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends