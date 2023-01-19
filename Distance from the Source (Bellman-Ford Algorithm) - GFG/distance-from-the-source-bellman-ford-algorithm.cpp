//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        int inf=100000000;
        vector<int>dis(V,inf);
        dis[S]=0;
        V--;
        while(V--){
            for(auto i:edges){
                if(dis[i[0]] !=inf){
                    int curr=dis[i[0]]+i[2];
                    
                    if(curr<dis[i[1]]){
                        dis[i[1]]=curr;
                    }
                }
            }
        }
        bool flag=false;
            for(auto i:edges){
                if(dis[i[0]] !=inf){
                    int curr=dis[i[0]]+i[2];
                    
                    if(curr<dis[i[1]]){
                        dis[i[1]]=curr;
                        flag=true;
                        break;
                    }
                }
            }  
            if(flag)return {-1};
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends