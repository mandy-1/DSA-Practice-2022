class Solution {
public:
    bool f(string& s1,string& s2,string& s3,int n,int m,int tot,vector<vector<int>>& dp){
        if(tot == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        
        int x=0 ,y=0;
        if(n-1 >= 0 and tot >= 0 and s1[n-1] == s3[tot-1]) x = f(s1,s2,s3,n-1,m,tot-1,dp);
        if(m-1 >= 0 and tot >= 0 and s2[m-1] == s3[tot-1]) y = f(s1,s2,s3,n,m-1,tot-1,dp);
        return dp[n][m] = x | y;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int tot = s3.size();
        
        if(n + m != tot) return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(s1,s2,s3,n,m,tot,dp);
    }
};