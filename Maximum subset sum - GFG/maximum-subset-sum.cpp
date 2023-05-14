//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    int sol(int idx,vector<int>& arr,int flag,vector<vector<int>>& dp){
        if(idx>=arr.size()) return 0;
        if(dp[idx][flag+1] != INT_MIN)return dp[idx][flag+1];
        int notTake=INT_MIN;
        int take = arr[idx] + sol(idx+1,arr,1,dp);
        if(flag || flag ==-1){
           notTake = sol(idx+1,arr,0,dp); 
        }
        return dp[idx][flag+1] = max(take,notTake);
    }  
  
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<vector<int>>dp(A.size(),vector<int>(3,INT_MIN));
        return sol(0,A,-1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends