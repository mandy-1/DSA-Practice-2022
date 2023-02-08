//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      
      int rowcnt=0,colcnt=0;
      int totalrow=n,totalcol=n;
      vector<long long int>ans;
      unordered_map<int,int>mp;
      unordered_map<int,int>mp2;
      for(int i=0;i<k;i++){
        if(!mp[arr[i][0]]){
            totalrow--;
            rowcnt++;
            mp[arr[i][0]]=1;
        }
        if(!mp2[arr[i][1]]){
            totalcol--;
            colcnt++;
            mp2[arr[i][1]]=1;
        }
        // cout<<totalrow<<" "<<n-colcnt<<" "<<totalcol<<" "<<n-rowcnt<<endl;
        ans.push_back(totalrow*(n-colcnt));
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends