//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin(),arr.end());
        int res=INT_MAX;
        int N=arr.size();
        for(int i=0;i<N;i++){
            int index=upper_bound(arr.begin(),arr.end(),arr[i]+k)-arr.begin()-1;
            int removalsReq=i+(N-index-1);
            res=min(res,removalsReq);
        }
        return res;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends