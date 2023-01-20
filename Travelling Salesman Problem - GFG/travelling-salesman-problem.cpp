//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int maxi=INT_MAX;
    bool fun(vector<bool>&vis){
        for(int i=0;i<vis.size();i++){
            if(vis[i]==false) return false;
        }
        return true;
    }
    int solve(vector<vector<int>>&cost,vector<bool>&vis,int k){
       if(fun(vis)) return cost[k][0];
       int ans=INT_MAX;
       int n=vis.size();
       for(int i=0;i<n;i++){
           if(k!=i  && vis[i]==false){
              vis[i]=1;
              ans=min(ans,cost[k][i]+solve(cost,vis,i));
              vis[i]=0;
           }
       }
       return ans;
    }
    int total_cost(vector<vector<int>>cost){
        int n=cost.size();
        vector<bool>vis(n);
        vis[0]=1;
        int as= solve(cost,vis,0);
        if(as==INT_MAX) return 0;
        else return as;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends