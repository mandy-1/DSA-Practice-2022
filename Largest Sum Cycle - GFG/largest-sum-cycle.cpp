//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{ 
  public:
 void dfs(int node,vector<bool>&visited,vector<bool>& dfsvisited,vector<int>& edges,vector<int>&prevSum,int currSum,int &ans){

         if(node==-1) return;

            if(!visited[node]){

                visited[node]=true;

                dfsvisited[node]=true;

                prevSum[node]=currSum;

               dfs(edges[node],visited,dfsvisited,edges,prevSum,currSum+edges[node],ans);

            }
            else if(visited[node]==true and dfsvisited[node]==true){

                ans=max(ans,currSum-prevSum[node]);

            }

        

        dfsvisited[node]=false;//backtrack

        

    }

  long long largestSumCycle(int n, vector<int> edges)

  {
        vector<int>prevSum(n,0);

        vector<bool>visited(n,false);

        vector<bool>dfsvisited(n,false);

        int ans=-1;

        for(int i=0;i<n;i++){

            if(!visited[i]){

                dfs(i,visited,dfsvisited,edges,prevSum,i,ans);   

            }

        }

      return ans;

  }
  
};


//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends