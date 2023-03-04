//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
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

typedef long long ll;
class Solution {
  public:
    ll sol(int idx,vector<vector<int>>& edg,vector<int>&a,int sign,vector<vector<ll>>& dp){
        if(edg[idx].size()==0){
            if(sign){
                return a[idx];
            }
            else{
                return -a[idx];
            }
        }
        if(dp[idx][sign] !=-1e18)return dp[idx][sign];
        ll ans=-1e18;
        for(int i=0;i<edg[idx].size();i++){
            if(sign){
                ans=max(ans,a[idx] + sol(edg[idx][i],edg,a,!sign,dp));
            }
            else{
                ans=max(ans,-a[idx] + sol(edg[idx][i],edg,a,!sign,dp));
            }
        }
        return dp[idx][sign] = ans;
    }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<vector<ll>>dp(N,vector<ll>(2,-1e18));
        vector<vector<int>>edg(N);
        for(int i=0;i<P.size();i++){
            if(P[i]==-1)continue;
            edg[P[i]-1].push_back(i);
        }
        ll ans=-1e18;
        
        for(int i=0;i<N;i++){
            ans=max(ans,sol(i,edg,A,1,dp));
            // cout<<ans<<" "<<i+1<<endl;
        }
        return ans;
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
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends