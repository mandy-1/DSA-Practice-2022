class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        int color =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i] = 1;
                col[i] = color;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it: graph[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                            col[it] = !col[node];
                        }
                        else if(col[it] != !col[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};