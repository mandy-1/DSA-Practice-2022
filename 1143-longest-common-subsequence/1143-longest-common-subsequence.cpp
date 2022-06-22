class Solution {
public:
    int solve(int idx1,int idx2,string &text1,string &text2,vector<vector<int>>& dp){
        if(idx1 <0 || idx2<0)return 0;
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2])return dp[idx1][idx2] = 1+solve(idx1-1,idx2-                     1,text1,text2,dp);
        return dp[idx1][idx2] = max(solve(idx1-1,idx2,text1,text2,dp), solve(idx1,idx2-             1,text1,text2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};