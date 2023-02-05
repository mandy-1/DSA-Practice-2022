//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int sol(int idx,int* arr,int& n,int prev,vector<vector<int>>& dp){
	    if(idx>=n)return 0;
	    if(dp[idx][prev+1] != -1)return dp[idx][prev+1];
	    int take=INT_MIN;
	    int notTake = INT_MIN;
	    if(prev ==-1 || arr[idx] > arr[prev] ){
	        take = arr[idx] + sol(idx+1,arr,n,idx,dp);
	    }
	    notTake = sol(idx+1,arr,n,prev,dp);
	    return dp[idx][prev+1] = max(take,notTake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return sol(0,arr,n,-1,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends