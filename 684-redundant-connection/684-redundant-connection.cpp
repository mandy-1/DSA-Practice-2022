class UnionFind {
  private:
    vector<int> parent;
  public:  
    UnionFind(int n){
        parent = vector<int>(n+1,-1);
    }
    
    int find(int x){
        if(parent[x]==-1) return x;
        return find(parent[x]);
    }
    
    void Union(int x,int y){
        int X = find(x);
        int Y = find(y);
        parent[X]=Y;
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind *uf = new UnionFind(n);
            
        for(auto x:edges){
            int a = uf->find(x[0]);
            int b = uf->find(x[1]);
            if(a==b) return {x[0],x[1]};
            
            uf->Union(x[0],x[1]);
        }
        return {};
    }
};