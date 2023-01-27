//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
    int mod = 1e9+7;
    int sol(string &str,int n,vector<int>&dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n]; 
        int cnt=0;
        if(str[n-1] >= '1') cnt = cnt + sol(str,n-1,dp)%mod;
        if(str[n-2] =='1' || str[n-2] == '2' && str[n-1] <='6') cnt = (cnt + sol(str,n-2,dp)%mod)%mod;
        
        return dp[n] = cnt%mod;
    }
	public:
		int CountWays(string str){
		    int n=str.length();
		    if(str[0]=='0') return 0;
		    vector<int>dp(n+1,-1);
		    
		    return sol(str,n,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends