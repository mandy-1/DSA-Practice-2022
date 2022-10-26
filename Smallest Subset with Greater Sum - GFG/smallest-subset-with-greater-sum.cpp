//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        sort(arr.begin(),arr.end());
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long int temp=sum;
        int cnt=0;
        int i=n-1;
        while(temp>=sum-temp && i>=0){
            temp -= arr[i];
            cnt++;
            i--;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends