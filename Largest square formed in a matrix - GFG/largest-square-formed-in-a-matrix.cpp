//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> arr(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<m;i++){
            arr[0][i]=mat[0][i];
            if(mat[0][i]==1)ans=1;
        }
        for(int i=0;i<n;i++){
            arr[i][0] = mat[i][0];
            if(mat[i][0]==1)ans=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1)
                    arr[i][j]=1+min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]));
                ans = max(ans,arr[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends