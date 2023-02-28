//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sol(int i,int& n,int* arr,int k,bool buy,vector<vector<vector<int>>>& dp){
        if(k==0)return 0;
        if(i==n)return 0;
        if(dp[i][k][buy] != -1)return dp[i][k][buy];
        int take=0;
        int notTake=0;
        if(buy){
            take= -arr[i] + sol(i+1,n,arr,k,!buy,dp);
        }
        else{
            take =arr[i] + sol(i+1,n,arr,k-1,!buy,dp);
        }
        notTake=sol(i+1,n,arr,k,buy,dp);
        return dp[i][k][buy] = max(take,notTake);
    }
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>>dp(N , vector<vector<int>>(K+1,vector<int>(2,-1)));
        return sol(0,N,A,K,1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends