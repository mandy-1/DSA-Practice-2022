//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>coin;
        coin = {2000,500,200,100,50,20,10,5,2,1};
        vector<int> count;
        for(int i=0;i<10;i++){
            if(N>=coin[i]){
                int n=N/coin[i];
                for(int j=0;j<n;j++){
                 count.push_back(coin[i]);   
                }
                N -= n*coin[i]; 
            }
            if(N==0) break;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends