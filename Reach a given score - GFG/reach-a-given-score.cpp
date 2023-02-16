//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
    int arr[3]={3,5,10};
    vector<vector<int>> dp(4,vector<int>(n+1,0));
    dp[3][0]=1;
    for(int ind=2;ind>=0;ind--){
        for(int score=0;score<=n;score++){
             if(arr[ind]<=score){
                 dp[ind][score]=dp[ind][score-arr[ind]]+dp[ind+1][score];
            }else{
                 dp[ind][score]=dp[ind+1][score];
            }
        }
    }
	return dp[0][n];
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends