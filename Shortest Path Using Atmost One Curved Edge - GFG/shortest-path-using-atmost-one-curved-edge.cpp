//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int dist1=edges[i][2];
            int dist2=edges[i][3];
            
            adj[u].push_back({v,dist1});
            adj[u].push_back({v-100000,dist2});     //1e5 is to distinguish b/w curved and normal path
            adj[v].push_back({u,dist1});
            adj[v].push_back({u-100000,dist2});
        }
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,a}});
        vector<int> dist1(n+1,INT_MAX);
        vector<int> dist2(n+1,INT_MAX);
        dist1[a]=0;
        dist2[a]=0;
        
        //applying dijkstra's algorithm
        while(!pq.empty()){
            int cdist=pq.top().first;
            int isCurvedIncluded=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
            
            //cout<<cdist<<" "<<isCurvedIncluded<<" "<<node<<endl;
            
            for(auto it:adj[node]){
                int tempNode=it.first;
                int tempDist=it.second;
                
                if(tempNode<=0 and isCurvedIncluded==0 
                    and dist2[tempNode+100000]>(cdist+tempDist)){
                        dist2[tempNode+100000]=(cdist+tempDist);
                        pq.push({(cdist+tempDist),{1,tempNode+100000}});
                    }
                
                if(tempNode>0){
                    if(isCurvedIncluded==0 and dist1[tempNode]>(cdist+tempDist)){
                            dist1[tempNode]=(cdist+tempDist);
                            pq.push({(cdist+tempDist),{isCurvedIncluded,tempNode}});
                    }
                    else if(isCurvedIncluded==1 and dist2[tempNode]>(cdist+tempDist)){
                            dist2[tempNode]=(cdist+tempDist);
                            pq.push({(cdist+tempDist),{isCurvedIncluded,tempNode}});                        
                    }
                }           
            }   
        }
        
        
        //returning answer
        if(dist1[b] == INT_MAX) return -1;
        return min(dist1[b],dist2[b]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends