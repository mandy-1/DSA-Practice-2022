//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string>ans;
    void sol(int i,int j,vector<vector<int>>&m,int& n, string s,vector<vector<int>> &visited){
        if(i==n-1 &&j==n-1){
            ans.push_back(s);
            return;
        }
        visited[i][j]=1;
        // down
        if(i+1<n && visited[i+1][j] ==0 && m[i+1][j] != 0){
            sol(i+1,j,m,n,s+'D',visited);
        }
        // up
        if(i-1>=0 && visited[i-1][j] ==0 && m[i-1][j] != 0){
            sol(i-1,j,m,n,s+'U',visited);
        }
        // left
        if(j-1>=0 && visited[i][j-1] ==0 && m[i][j-1] != 0){
            sol(i,j-1,m,n,s+'L',visited);
        }
        // right
        if(j+1<n && visited[i][j+1] ==0 && m[i][j+1] != 0){
            sol(i,j+1,m,n,s+'R',visited);
        }
        visited[i][j]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0)return {"-1"};
        vector<vector<int>>visited(n,vector<int>(n,0));
        sol(0,0,m,n,"",visited);
        if(ans.size()==0)return {"-1"};
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends