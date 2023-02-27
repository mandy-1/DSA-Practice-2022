//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    pair<int,int> solve(vector<int>&arr)
    {   
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = 0;
        int sum = 0, ans = 0;
        
        int first = -1, second = -1;
        
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(mp.count(sum))
            {
                int len = i - mp[sum] + 1;
                if(len > ans)
                {
                    ans = len;
                    first = mp[sum];
                    second = i;
                }
            }
            else
            mp[sum] = i+1;
        }
        
        return {first, second};
    }
  
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> matrix)
  {
      int row = matrix.size();
      int col = matrix[0].size();
      
      int resultvectorsize = 0;
      
      int colstart = -1, colend = -1, rowstart = -1, rowend = -1;
      
      for(int i=0; i<row; i++)
      {
          vector<int> dp(col, 0);
          
          for(int j = i; j<row; j++)
          {
              for(int k = 0; k<col; k++)
              {
                  dp[k] = dp[k] + matrix[j][k];
              }
              
              pair<int,int> p = solve(dp);
              
              if(p.first != -1)
              {
                  int tempsize = (j - i + 1)*(p.second - p.first + 1);
                  
                  if(tempsize > resultvectorsize)
                  {
                      rowstart = i;
                      rowend = j;
                      colstart = p.first;
                      colend = p.second;
                      
                      resultvectorsize = tempsize;
                  }
                  else if(tempsize == resultvectorsize)
                  {
                      if(p.first < colstart)
                      {
                          rowstart = i;
                          rowend = j;
                          colstart = p.first;
                          colend = p.second;
                      }
                  }
              }
          }
      }
      
      vector<vector<int>> result;
      if(rowstart == -1) return result;
     
      int rowLength = rowend - rowstart + 1;
      int colLength = colend - colstart + 1;
      
      result.resize(rowLength, vector<int>(colLength, 0));
      
      for(int i=0; i<rowLength; i++)
      {
          int slidecol = colstart;
          for(int j=0; j<colLength; j++)
          {
              result[i][j] = matrix[rowstart][slidecol];
              slidecol++;
          }
          rowstart++;
      }
      
      return result;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends