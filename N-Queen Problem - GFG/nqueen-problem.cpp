//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    vector<vector<int>>ans;
    bool isvalid(int i,int j,vector<vector<int>>&m,int& n){
        // digonal 1
        int p=i,q=j;
        i--,j--;
        while(i>=0 && j>=0){
            if(m[i][j]==1)return false;
            i--;
            j--;
        }
        // up
        i=p,j=q;
        i--;
        while(i>=0){
            if(m[i][j]==1)return false;
            i--;
        }
        // digonal 2
        i=p,j=q;
        i--,j++;
        while(i>=0 && j<n){
            if(m[i][j]==1)return false;
            i--;
            j++;
        }
        return true;
    }
    
    void sol(int i,int j,int& n,vector<vector<int>>& m,vector<int>path){
        if(i==n){
            ans.push_back(path);
            return;
        }
        for(int j=0;j<n;j++){
            if(isvalid(i,j,m,n)){
                m[i][j]=1;
                path.push_back(j+1);
                sol(i+1,j,n,m,path);
                path.pop_back();
                m[i][j]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>m(n,vector<int>(n,0));
        sol(0,0,n,m,{});
        // if(ans.size()==0)return {{-1}};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends