//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    bool iscelab(int& i,int& n,vector<vector<int> >& arr){
        for(int j=0;j<n;j++){
            if(j==i)continue;
            if(arr[j][i]==0)return false;
        }
        return true;
    }
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(arr[i][j]==1)break;
                cnt++;
            }
            // cout<<cnt<<" ";
            if(cnt==n-1){
                if(iscelab(i,n,arr)){
                    return i;
                }
            }
        } 
        // cout<<endl;
        return -1;
    }
    
    // 0 0 0
    // 0 0 0
    // 0 0 0
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends