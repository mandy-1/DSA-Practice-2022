//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      int n = a[0].size();
      int prev1,curr1,prev2,curr2;
      
      prev1 = a[0][n-1] + x[0];
      prev2 = a[1][n-1] + x[1];
     
      for(int i=n-2; i>=0; i--){
          curr1 = a[0][i] + min(prev1, T[0][i+1]+prev2);
          curr2 = a[1][i] + min(prev2, T[1][i+1]+prev1);
          prev1 = curr1;
          prev2 = curr2;
      }
      
      curr1 += e[0];
      curr2 += e[1];
      
      return min(curr1, curr2);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends