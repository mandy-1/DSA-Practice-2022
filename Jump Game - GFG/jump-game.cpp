//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool f(int i,int nums[],vector<int>& dp,int& N){
        // cout<<i<<" ";
        if(nums[i]==0 && i!=N-1)return false;
        if(nums[i]>N-i-1 || i>=N-1)return true;
        if(dp[i] != -1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(f(i+j,nums,dp,N)) return dp[i]=true;
        }
        return dp[i] = false;
    }    
    int canReach(int nums[], int N) {
        vector<int>dp(N+1,-1);
        return f(0,nums,dp,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends