//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1003;
    int sol(int i,int j,string& s,bool isTrue,vector<vector<vector<int>>>& dp){
        if(i>j)return 0;
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else {
                return s[i]=='F';
            }
        }
        if(dp[i][j][isTrue] != -1)return dp[i][j][isTrue];
        int ans=0;
        for(int k=i+1;k<=j;k+=2){
            int x1 = sol(i,k-1,s,1,dp);
            int x2 = sol(k+1,j,s,1,dp);
            int y1 = sol(i,k-1,s,0,dp);
            int y2 = sol(k+1,j,s,0,dp);   
            int cur=0;
            if(s[k]=='|'){
                if(isTrue){
                    cur = (x1*x2%mod + y2*x1%mod + y1*x2%mod)%mod;    
                }
                else{
                    cur = y1*y2%mod; 
                }
                
                ans = (ans + cur)%mod;
            }
            else if(s[k]=='&'){
                if(isTrue){
                    cur = x1*x2%mod;                    
                }
                else{
                    cur = (x1*y2%mod +x2*y1%mod + y1*y2%mod)%mod;
                }

                ans = (ans + cur)%mod;
            }
            else{
                if(isTrue){
                    cur= (y2*x1%mod + y1*x2%mod)%mod;    
                }
                else{
                    cur = (x1*x2%mod + y1*y2%mod)%mod;
                }
                ans= (ans + cur)%mod;
            }
        }
        return dp[i][j][isTrue] = ans;
    }
    int countWays(int N, string S){
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return sol(0,N-1,S,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends