//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int j=arr.size()-1;
        while(j>0){
            if(arr[j]>arr[j-1])break;
            j--;
        }
        j--;
        if(j<0){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        int i=j+1;
        int temp=i;
        while(i<arr.size()){
            if(arr[j]<arr[i]){
                if(arr[temp]>arr[i]){
                    temp=i;
                }
            }
            i++;
        }
        swap(arr[j],arr[temp]);
        // cout<<j<<" "<<temp<<endl;
        reverse(arr.begin()+j+1,arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends