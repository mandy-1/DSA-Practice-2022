//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &a,vector<int> &b){
        stack<int>st;
        int i=0,j=0;
        while(N){
            if(st.empty() || st.top() != b[j]){
                while(i<a.size() && a[i] != b[j]){
                    st.push(a[i]);
                    i++;
                }
                if(i==a.size())return 0;
                else {
                    j++,i++;
                }
            }
            else if(st.top()==b[j]){
                st.pop();
                j++;
            }
            N--;
        }
        if(st.empty())return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends