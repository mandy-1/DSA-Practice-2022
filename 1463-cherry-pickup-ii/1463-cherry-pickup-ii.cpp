class Solution {
public:
    int dp[100][100][100];
    int rec(int i,int idx1,int idx2,vector<vector<int>> &grid){
        if(i==grid.size()-1){
            return idx1==idx2?grid[i][idx1]:grid[i][idx1]+grid[i][idx2];
        }
        int curr=INT_MIN;
        if(dp[i][idx1][idx2]!=-1) return dp[i][idx1][idx2];
        int k=idx1==idx2?grid[i][idx1]:grid[i][idx1]+grid[i][idx2];
        
        // go first robot left
        if(idx1-1>=0){
            if(idx2-1>=0) curr=max(curr,k+rec(i+1,idx1-1,idx2-1,grid));   // second robot left
            curr=max(curr,k+rec(i+1,idx1-1,idx2,grid)); // second robot same
            if(idx2+1<grid[0].size()) curr=max(curr,k+rec(i+1,idx1-1,idx2+1,grid)); // second robot right;
        }
        // first robot same
        if(idx2-1>=0) curr=max(curr,k+rec(i+1,idx1,idx2-1,grid));
        curr=max(curr,k+rec(i+1,idx1,idx2,grid));
        if(idx2+1<grid[0].size()) curr=max(curr,k+rec(i+1,idx1,idx2+1,grid));
        
        //first robot right
        if(idx1+1<grid[0].size()){
            if(idx2-1>=0) curr=max(curr,k+rec(i+1,idx1+1,idx2-1,grid));
            curr=max(curr,k+rec(i+1,idx1+1,idx2,grid));
            if(idx2+1<grid[0].size()) curr=max(curr,k+rec(i+1,idx1+1,idx2+1,grid));
        }
        
        return dp[i][idx1][idx2]=curr;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,grid[0].size()-1,grid);
    }
};