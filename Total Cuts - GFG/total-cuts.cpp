//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &arr){
        vector<int>minarr(N-1),maxarr(N-1);
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<N-1;i++){
            maxi=max(maxi,arr[i]);
            maxarr[i]=maxi;
        }
        for(int i=N-1;i>0;i--){
            mini = min(mini,arr[i]);
            minarr[i-1]=mini;
        }
        int ans=0;
        // for(int i=0;i<N-1;i++){
        //     cout<<minarr[i]<<" "<<maxarr[i]<<endl;
        // }
        for(int i=0;i<N-1;i++){
            if(minarr[i]+maxarr[i] >=K){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends