//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int inf=1e9+7;
class Solution {
  public:
    long long int sol(int i,int j,vector<vector<long long>>&dp,int& m,int& n){
        if(i==m-1 &&j==n-1)return 1;
        if(i>=m || i<0 ||j>=n || j<0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        long long rgt=sol(i,j+1,dp,m,n);
        long long dwn=sol(i+1,j,dp,m,n);
        return dp[i][j]= (rgt+dwn)%inf;
    } 
    long long int numberOfPaths(int m, int n){
        vector<vector<long long>>dp(m,vector<long long>(n,-1));
        return sol(0,0,dp,m,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends