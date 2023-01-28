//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isP(string s)
    {
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                return false;
            }
        }
        return true;
    }
    
    int printS(string s,vector<int>& dp)
    {
        if(s.size()==0)
        {   
            return 0;
        }
        int temp=s.size();
        if(dp[temp] != -1)return dp[temp];
        int cur=1e9;
        for(int i= 0;i<temp;i++)
        {
            string qpr= s.substr(0,i+1);
            string ros = s.substr(i+1);
            if(isP(qpr))
            {
                cur = min(1+printS(ros,dp),cur);
            }
        }
        return dp[temp]=cur;
    }
    
    int palindromicPartition(string s)
    {   int n=s.size();
        vector<int>dp(n+1,-1);
        return printS(s,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends