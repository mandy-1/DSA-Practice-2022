//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool DFS_Rec(vector<int> adj[], int s, vector<bool>& visit, vector<bool>& st){
        
        visit[s] = true;
        st[s] = true;
        
        for(auto u : adj[s]){
            
            if(visit[u] == false){
                if(DFS_Rec(adj, u, visit, st))
                    return true;
            }
            else if(st[u] == true)
                return true;
        }
        st[s] = false;
        return false;
    }
  
    bool DFS_Main(vector<int> adj[],int V){
        vector<bool> visit(V, false), st(V, false);
        for(int i=0; i<V; i++){
            if(visit[i] == false){
                if(DFS_Rec(adj, i, visit, st))
                    return true;
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        return DFS_Main(adj, V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends