//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool sol(int i,int j,int k,string& a,string& b,string& c,vector<vector<int>>& dp){
        if(i>=a.length() && j>=b.length() && k>=c.length())return true; 
        if(dp[i][j] != -1)return dp[i][j];
        bool case1=false;
        bool case2=false;
        if(i<a.length() && a[i]==c[k]){
            case1 = sol(i+1,j,k+1,a,b,c,dp);
        }
        if(j<b.length() && b[j]==c[k]){
            case2 = sol(i,j+1,k+1,a,b,c,dp);
        }
        return dp[i][j] = case1||case2;
    }
    bool isInterleave(string A, string B, string C) 
    {   
        vector<vector<int>>dp(A.length()+1,vector<int>(B.length()+1,-1));
        if(A.length()+B.length() != C.length())return false;
        return sol(0,0,0,A,B,C,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends