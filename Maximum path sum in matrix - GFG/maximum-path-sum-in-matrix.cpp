//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int sol(int idx,int j,int& N,vector<vector<int>>& arr,vector<int>& dir,vector<vector<int>>& dp){
        if(idx>=N || j<0 || j>=N)return 0;
        if(dp[idx][j] != -1)return dp[idx][j];
        int ans = arr[idx][j];
        int maxi=INT_MIN;
        for(int i=0;i<3;i++){
            maxi = max(maxi,sol(idx+1,j+dir[i],N,arr,dir,dp));
        }
        return dp[idx][j] = ans+maxi;
    }

    int maximumPath(int N, vector<vector<int>> matrix)
    {
        vector<int>dir = {-1,0,1};
        vector<vector<int>>dp(N,vector<int>(N,-1));
        int ans=-1;
        for(int i=0;i<N;i++){
            ans = max(ans,sol(0,i,N,matrix,dir,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends