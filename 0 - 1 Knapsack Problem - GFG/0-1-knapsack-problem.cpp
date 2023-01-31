//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int sol(int idx,int wt[],int val[],int& n,int W,vector<vector<int>>& dp){
      if(W==0)return 0;
      if(idx>=n && W!=0)return 0;
      if(dp[idx][W] != -1)return dp[idx][W];
      int take=0;
      int notTake=0;
      if(wt[idx]<=W){
          take=val[idx]+sol(idx+1,wt,val,n,W-wt[idx],dp);
      }
      notTake = sol(idx+1,wt,val,n,W,dp);
    //   cout<<idx<<" "<<W<<" "<<max(take,notTake)<<endl;
      return dp[idx][W] = max(take,notTake);
  }    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return sol(0,wt,val,n,W,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends