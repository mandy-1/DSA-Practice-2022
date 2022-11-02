//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int N,int arr[],int index,int first,int sum,vector<vector<int>>&dp){

        if(index==N){

            if(first==sum)return 1;

            return 0;

        }

        if(first==sum)return 1;

        if(dp[index][first]!=-1)return dp[index][first];

        int incl=solve(N,arr,index+1,first+arr[index],sum-arr[index],dp);

        int excl=solve(N,arr,index+1,first,sum,dp);

        return dp[index][first]=incl+excl;

    }

    int equalPartition(int N, int arr[])

    {

        int sum=0;

        for(int i=0;i<N;i++){

            sum+=arr[i];

        }

        vector<vector<int>>dp(N,vector<int>(sum,-1));

        int index=0; 

        int ans=solve(N,arr,index,0,sum,dp);

        return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends