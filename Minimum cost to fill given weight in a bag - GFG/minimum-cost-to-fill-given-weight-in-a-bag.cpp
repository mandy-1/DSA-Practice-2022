//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	int sol(int idx,int wg,int* cost,int& n,vector<vector<int>>& dp){
	    if(wg==0)return 0;
	    if(idx >=n )return 1e9;
	    if(wg<idx)return 1e9;
	    if(dp[idx][wg] != -1)return dp[idx][wg];
	    int take=1e9;
	    int notTake=1e9;
	    if(cost[idx] != -1 ){
	        take=cost[idx]+sol(idx,wg-idx-1,cost,n,dp);
	    }
	    notTake = sol(idx+1,wg,cost,n,dp);
	    return dp[idx][wg] = min(take,notTake);
	}

	public:
	int minimumCost(int cost[], int N, int W) 
	{   
	    vector<vector<int>>dp(N,vector<int>(W+1,-1));
	    int ans = sol(0,W,cost,N,dp);
	    if(ans==1e9)return -1;
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends