//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public: 
    int selectKcities(int n, int k, vector<vector<int>>& mat){
        int ans = INT_MAX, maxx;
        for(int i=0;i<n;i++){
            maxx = i;
            ans = min(ans, f(n, k, mat, maxx));
        }
        return ans;
    }
    
    int f(int n, int k, vector<vector<int>>& mat, int maxx){
        vector<int>dist(n, INT_MAX);
        vector<int>atms;
        int t = k;
        
        while(t--){
            atms.push_back(maxx);
            for(int i=0;i<n;i++){
                dist[i] = min(dist[i], mat[maxx][i]);
            }
            maxx = max_element(dist.begin(), dist.end())-dist.begin();
        }
        return dist[maxx];
    }
};



//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> mat(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        
        Solution obj;
        int ans = obj.selectKcities(n, k, mat);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends