//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edges)
  {   unordered_map<int,int>mp;
      int maxi=0,ans=0;
      for(int i=0;i<edges.size();i++){
        //   cout<<maxi<<' '<<ans<<endl;
          if(edges[i]==-1)continue;
          mp[edges[i]]+=i;          
          if(maxi<mp[edges[i]]){
              ans=edges[i];
              maxi=mp[edges[i]];
          }
          else if(mp[edges[i]]==maxi){
              ans=max(edges[i],ans);
          }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
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
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends