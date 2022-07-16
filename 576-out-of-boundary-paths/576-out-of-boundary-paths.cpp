class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[51][51][51];
    long dfs(int m, int n, int maxMove, int i, int j)
    {
        if(i>=m || i<0 || j>=n || j<0) return 1;
        if(maxMove <= 0) return 0;
        
        if(memo[i][j][maxMove] != -1)
        {
            return memo[i][j][maxMove];
        }
        
        long res = 0;
        res += dfs(m, n, maxMove-1, i+1, j);
        res += dfs(m, n, maxMove-1, i, j-1);
        res += dfs(m, n, maxMove-1, i-1, j);
        res += dfs(m, n, maxMove-1, i, j+1);
        
        return memo[i][j][maxMove] = res%MOD;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof(memo));
        return dfs(m,n,maxMove, startRow, startColumn)%MOD;
    }
};