//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    int sol(int n,int& x,int& y,int& z,vector<int>& dp){
        if(n==0)return 0;
        if(dp[n] != -1)return dp[n];
        int num1=INT_MIN,num2=INT_MIN,num3=INT_MIN;
        if(n>=x) num1=sol(n-x,x,y,z,dp);
        if(n>=y) num2=sol(n-y,x,y,z,dp);
        if(n>=z) num3=sol(n-z,x,y,z,dp);
        return dp[n] = 1+max(num1,max(num2,num3));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {   
        vector<int>dp(n+1,-1);
        int ans=sol(n,x,y,z,dp);
        if(ans<0)return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends