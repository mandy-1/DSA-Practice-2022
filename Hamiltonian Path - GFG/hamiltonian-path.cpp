//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,int count,int n) {
        vis[node] = 1;
        
        count++;
        if(count == n)
            return true;
        
        for(auto i: adj[node]) {
            if(!vis[i]){
                if(dfs(i,adj,vis,count,n))
                    return true;
            }
        }
        vis[node] = 0;
        return false;
    }
    bool check(int n,int m,vector<vector<int>>&edges)
    {
        vector<int>adj[n+1];
        for(auto i: edges) {
            int u = i[0]-1, v = i[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n+1);
        for(int i=0;i<n;i++) {
            if(!vis[i] and dfs(i,adj,vis,0,n))    
                return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends