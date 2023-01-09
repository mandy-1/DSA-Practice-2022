//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{   
    public:
 int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)

 {
     vector<vector<int>> vis(n,vector<int>(n,0));
     int p1 = KnightPos[0];
     int p2 = KnightPos[1];
     int t1 = TargetPos[0];
     int t2 = TargetPos[1];
     queue<pair<int,int>> q;
     q.push({p1-1,p2-1});

     while(!q.empty())
     {
         int i = q.front().first;
         int j = q.front().second;
         q.pop();
         if ((i+1)<n && (i+1)>=0 && (j+2)>=0 && (j+2)<n && vis[i+1][j+2] == 0)
         {
             q.push({i+1,j+2});
             vis[i+1][j+2] = vis[i][j] + 1; 
         }
         if ((i-1)<n && (i-1)>=0 && (j+2)>=0 && (j+2)<n && vis[i-1][j+2] == 0)
         {
             q.push({i-1,j+2});
             vis[i-1][j+2] = vis[i][j] + 1; 
         }

         if ((i+1)<n && (i+1)>=0 && (j-2)>=0 && (j-2)<n && vis[i+1][j-2] == 0)
         {
             q.push({i+1,j-2});
             vis[i+1][j-2] = vis[i][j] + 1; 
         }
         if ((i-1)<n && (i-1)>=0 && (j-2)>=0 && (j-2)<n && vis[i-1][j-2] == 0)
         {
             q.push({i-1,j-2});
             vis[i-1][j-2] = vis[i][j] + 1; 
         }
         if ((i+2)<n && (i+2)>=0 && (j+1)>=0 && (j+1)<n && vis[i+2][j+1] == 0)
         {
             q.push({i+2,j+1});
             vis[i+2][j+1] = vis[i][j] + 1; 
         }
         if ((i-2)<n && (i-2)>=0 && (j+1)>=0 && (j+1)<n && vis[i-2][j+1] == 0)
         {
             q.push({i-2,j+1});
             vis[i-2][j+1] = vis[i][j] + 1; 
         }
         if ((i-2)<n && (i-2)>=0 && (j-1)>=0 && (j-1)<n && vis[i-2][j-1] == 0)
         {
             q.push({i-2,j-1});
             vis[i-2][j-1] = vis[i][j] + 1; 
         }
         if ((i+2)<n && (i+2)>=0 && (j-1)>=0 && (j-1)<n && vis[i+2][j-1] == 0)
         {
             q.push({i+2,j-1});
             vis[i+2][j-1] = vis[i][j] + 1; 
         }
     }
     return vis[t1-1][t2-1];
 }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends