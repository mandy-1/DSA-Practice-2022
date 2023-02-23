//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod=1e9+7;
    int sol(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==grid.size()-1 && j==grid[0].size()-1)return 1;
        if(i>=grid.size()||j>=grid[0].size() || grid[i][j]==0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        
        int take1=sol(i+1,j,grid,dp)%mod;
        int take2=sol(i,j+1,grid,dp)%mod;
        return dp[i][j]=(take1+take2)%mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[0][0]==0 || grid[n-1][m-1]==0)return 0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return sol(0,0,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends