//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int kaden(vector<int>& arr,int& c){
      int ans=INT_MIN,sum=0;
      for(int i=0;i<c;i++){
          sum+=arr[i];
          ans=max(ans,sum);
          if(sum<0)sum=0;
      }
      return ans; 
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> arr) {
        int ans=INT_MIN;
        for(int p=0;p<R;p++){
            vector<int>temp(C,0);
            for(int i=p;i<R;i++){
                for(int j=0;j<C;j++){
                   temp[j] += arr[i][j];
                }
                ans = max(ans,kaden(temp,C));
                // cout<<ans<<" ";
            }            
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends