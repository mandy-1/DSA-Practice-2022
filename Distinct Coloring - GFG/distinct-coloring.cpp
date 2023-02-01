//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
long long int sol(int prev,int idx, int &n, int r[],int g[],int b[], vector<vector<long long int>> &dp){
        if(idx == n){
            return 0;
        }
        
        long long int take1=1e11,take2=1e11;
        
        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        
        if(prev ==0){
            take1 = g[idx] + sol(1,idx+1,n, r,g,b,dp);
            take2 = b[idx] + sol(2,idx+1,n, r,g,b,dp);
        }

        if( prev ==1){
            take1 = r[idx] + sol(0,idx+1,n,r,g,b,dp);
            take2 = b[idx] + sol(2,idx+1,n,r,g,b,dp);
        }
        if( prev ==2){
            take1 = g[idx] + sol(1,idx+1, n,r,g,b,dp);
            take2 = r[idx] + sol(0,idx+1,n,r,g,b,dp);
        }  
        return dp[idx][prev] = min(take1,take2);
    }

    long long int distinctColoring(int N, int r[], int g[], int b[]){
        long long int mini=1e11;
        vector<vector<long long int>> dp(N,vector<long long int> (4,-1));
        for(int i=0;i<3;i++){
            mini=min(mini,sol(i, 0, N,r,g,b, dp));    
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends