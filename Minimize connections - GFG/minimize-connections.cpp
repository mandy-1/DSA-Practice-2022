//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumConnections(vector<vector<int>> &connections,int n)
        {
        if(connections.size()<n-1)return -1;
        vector<vector<int>>edg(n);
        for(int i=0;i<connections.size();i++){
            edg[connections[i][0]].push_back(connections[i][1]);
            edg[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    auto temp=q.front();
                    q.pop();
                    for(int j=0;j<edg[temp].size();j++){
                        if(!vis[edg[temp][j]]){
                            q.push(edg[temp][j]);
                            vis[edg[temp][j]]=1;
                        }
                    }
                }
            }
        }
        return cnt-1;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> c(m,vector<int> (2));
        for(auto &j:c)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(c,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends