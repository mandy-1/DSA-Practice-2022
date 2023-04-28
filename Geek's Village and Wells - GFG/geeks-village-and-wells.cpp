//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &mat){
        vector<vector<bool >> v(n,vector<bool>(m,false));
        vector<vector<int>> res(n,vector<int>(m,0));
        queue <pair<int,int>> q;
        int r[4] = {-1,0,1,0};
        int c[4] = {0,1,0,-1};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'W'){
                    v[i][j] = 1;
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            for(int i = 0 ; i < 4 ; i++){
                int nr = x+r[i];
                int nc = y+c[i];
                if(nr < n && nc < m && nr >= 0 && nc >= 0 && !v[nr][nc] && mat[nr][nc] != 'N'){
                    res[nr][nc] = res[x][y]+2;
                    q.push({nr,nc});
                    v[nr][nc] = 1;
                }
            }
            
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'N' || mat[i][j] == '.'){
                    res[i][j] = 0;
                }
                else if(mat[i][j] == 'H'){
                    if(res[i][j] == 0){
                        res[i][j] = -1;
                    }
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends