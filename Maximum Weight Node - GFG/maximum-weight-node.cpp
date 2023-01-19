//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {    unordered_map<int,int> mp;
        int i=0;
        while(i<n){
            if(edge[i]!=-1){
                mp[edge[i]] += i;
            }
            i++;
        }
        int m=INT_MIN, index=0;
        for(auto it:mp){
            if(m<=it.second){
                m = it.second;
                index = it.first;
            }
        }
        return index;
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