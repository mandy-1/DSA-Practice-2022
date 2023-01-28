//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool sol(string a, string b ,unordered_map<string,unordered_map<string,int>>& dp){
        if(a.compare(b)==0)return true;
        if(a.length()<=1)return false;
        
        int n=a.length();
        if(dp[a][b]==1)return 1;
        if(dp[a][b]==-1)return false;
        for(int i=1;i<=n-1;i++){
          bool case1 = sol(a.substr(0,i),b.substr(0,i),dp)&&sol(a.substr(i),b.substr(i),dp);
          bool case2 = sol(a.substr(0,i),b.substr(n-i),dp)&&sol(a.substr(i),b.substr(0,n-i),dp);
          if(case1 || case2)return dp[a][b]=true;
        }
        dp[a][b]=-1;
        return false;
    }
    
    bool isScramble(string s1, string s2){
        int n1=s1.length();
        int n2=s2.length();
        if(n1 != n2)return false;
        if(s1=="" && s2 =="")return true;
        unordered_map<string,unordered_map<string,int>>dp;
        return sol(s1,s2,dp);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends