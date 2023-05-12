//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int i=0,ans=0,prev=-1;
        bool flag=false;
        while(i<n){
            if(arr[i]==0){
                flag=true;
                if(prev != -1){
                    if(i-prev > 1){
                        ans++;
                    }
                }
                else{
                    if(i>0)
                    ans++;    
                }
                prev=i;
            }
            i++;
        }
        if(!flag){
            return -1;
        }
        if(prev != n-1)ans++;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends