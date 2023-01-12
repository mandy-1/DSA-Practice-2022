//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        auto temp=q.front();
                        q.pop();
                        for(int p=0;p<8;p++){
                            int x=temp.first+dir[p][0];
                            int y=temp.second+dir[p][1];
                            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1'){
                                q.push({x,y});
                                grid[x][y]='0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends