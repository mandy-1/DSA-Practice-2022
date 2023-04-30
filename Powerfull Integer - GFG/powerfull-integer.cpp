//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &interval,int k){
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[interval[i][0]]++;
            mp[interval[i][1]+1]--;
        }
        int ans=-1,cur=0;
        for(auto i:mp){
            if(cur>=k && ans>=0){
                ans=max(ans,i.first-1);
            }
            cur+=i.second;
            if(cur>=k){
                ans = i.first;
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
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends