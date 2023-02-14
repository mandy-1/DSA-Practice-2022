//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int sol(int idx,vector<vector<int>>& col,int prev,int& N,vector<vector<int>>& dp){
        if(idx>=N)return 0;
        if(dp[idx][prev] != -1)return dp[idx][prev];
        if(prev==0){
            return(dp[idx][prev]= min(sol(idx+1,col,1,N,dp)+col[idx][1],sol(idx+1,col,2,N,dp)+col[idx][2]));
        }
        else if(prev==1){
            return dp[idx][prev] = min(sol(idx+1,col,0,N,dp)+col[idx][0],sol(idx+1,col,2,N,dp)+col[idx][2]);
        }
        return dp[idx][prev] = min(sol(idx+1,col,0,N,dp)+col[idx][0],sol(idx+1,col,1,N,dp)+col[idx][1]);
    }

    int minCost(vector<vector<int>> &col, int N) {
        int ans=INT_MAX;
        vector<vector<int>>dp(N,vector<int>(3,-1));
        for(int i=0;i<3;i++){
            int cur=sol(1,col,i,N,dp)+col[0][i];
            // cout<<cur<<endl;
            ans = min(ans,cur);
        }
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<3;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends