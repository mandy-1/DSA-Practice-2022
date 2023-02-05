//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int sol(int x,int y,string& s1,string& s2,vector<vector<int>>& dp){
	        if(x<0 || y<0)return 0;
	        if(dp[x][y] != -1)return dp[x][y];
	        if(x != y && s1[x]==s2[y]) return dp[x][y] = 1+sol(x-1,y-1,s1,s2,dp);
	        return dp[x][y] = max(sol(x,y-1,s1,s2,dp),sol(x-1,y,s1,s2,dp));
	    }
		int LongestRepeatingSubsequence(string str){
		    string s=str;
		    int n=s.length();
		    vector<vector<int>>dp(n,vector<int>(n,-1));
		    return sol(n-1,n-1,str,s,dp);
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
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends