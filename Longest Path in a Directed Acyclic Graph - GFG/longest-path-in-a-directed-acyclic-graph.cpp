//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            priority_queue<pair<int,int>>pq;
            vector<int>dis(v,INT_MIN);
            vector<vector<pair<int,int>>>edg(v);
            for(auto it:edges){
                edg[it[0]].push_back({it[2],it[1]});
            }
            dis[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                auto node = pq.top();
                pq.pop();
                for(auto i:edg[node.second]){
                    if(i.first+dis[node.second]>dis[i.second]){
                        dis[i.second]=i.first+dis[node.second];
                        pq.push({i.first+dis[node.second],i.second});
                    }
                }
            }
            return dis;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends