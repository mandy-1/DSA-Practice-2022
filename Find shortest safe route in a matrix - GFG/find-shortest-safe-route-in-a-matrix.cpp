//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool issafe(int &i, int &j, int &n, int &m){
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        int R=mat.size(),C=mat[0].size();
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<4;k++){  
                        int newi=i+dx[k];
                        int newj=j+dy[k];
                        if(issafe(newi,newj,R,C) and mat[newi][newj]!=0){
                            mat[newi][newj]=-1;
                        }
                    }
                }
            }
        }
        vector<vector<int>> vis(R,vector<int>(C,0));
        for(int i=0;i<R;i++){
            if(mat[i][0]==1){
                q.push({{i,0},1});
                vis[i][0]=1;
            }
        }
        int ans=INT_MAX;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];
                if(issafe(newi,newj,R,C) and mat[newi][newj]==1 and vis[newi][newj]==0){
                    vis[newi][newj]=1;
                    q.push({{newi,newj},dis+1});
                    if(newj==(C-1)){
                        ans=min(ans,dis+1);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends