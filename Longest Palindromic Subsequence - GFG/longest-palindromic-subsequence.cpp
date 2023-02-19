//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalSubseq(string s, int i, int j,vector<vector<int>> &dp) {
        if (i == j) return 1;
        if (i > j) return 0;
    
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
    
        if (s[i] == s[j]) {
            dp[i][j]= 2 + longestPalSubseq(s, i + 1, j - 1,dp);
        }
        else {
            dp[i][j]= max(longestPalSubseq(s, i + 1, j,dp),longestPalSubseq(s, i, j - 1,dp));
          }
          return dp[i][j];
    }

    int longestPalinSubseq(string A) {

        int n=A.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return longestPalSubseq(A,0,n-1,dp);

    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends