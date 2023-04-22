//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int>arr2;
        arr2=arr;
        unordered_map<int,long long>mp;
        sort(arr2.begin(),arr2.end());
        // for(int i=0;i<n;i++){
        //     cout<<arr2[i]<<" ";
        // }
        // cout<<endl;
        long long sum=0,prev=0;
        for(int i=0;i<n;i++){
            // cout<<arr2[i]<<" "<<sum<<" "<<prev<<endl;
            if(i>0 && arr2[i-1] != arr2[i])
                mp[arr2[i]]=sum;
            else
                mp[arr2[i]]=prev;
            
            if(i>0 && arr2[i-1] != arr2[i]){
                // cout<<arr2[i]<<" "<<arr2[i-1]<<endl;
                // cout<<i<<" "<<prev<<" "<<sum<<endl;
                prev=sum;
            }
            sum+=arr2[i];
            // cout<<arr2[i]<<" "<<sum<<" "<<prev<<endl;
        }
        vector<long long>ans;
        for(int i=0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }
        // cout<<endl;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends