//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<int>vis(V+1,0);
        int ans=0;
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                vis[i]=1;
                queue<int>q;
                int cnt=0;
                for(int j=0;j<adj[i].size();j++){
                    if(!vis[adj[i][j]]){
                        vis[adj[i][j]]=1;
                        q.push(adj[i][j]);
                    }
                }
                cnt=adj[i].size();
                bool flag=false;
                while(!q.empty()){
                    auto temp=q.front();
                    q.pop();
                    if(cnt!=adj[temp].size()){
                        flag=true;
                    }
                    for(int j=0;j<adj[temp].size();j++){
                        if(!vis[adj[temp][j]]){
                            flag=true;
                            q.push(adj[temp][j]);
                            vis[adj[temp][j]]=1;
                        }
                    }
                }
                if(!flag){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends