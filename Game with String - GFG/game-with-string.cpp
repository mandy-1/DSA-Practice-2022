//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int>mp;
        priority_queue<int>q;
        for(int i=0;i<s.length();i++){
            ++mp[s[i]];
            // cout<<s[i]<<" "<<mp[s[i]]<<endl;
        }
        for(auto i:mp){
            // cout<<mp[s[i]]<<" ";
            q.push(i.second);
        }
        // cout<<endl;
        while(k){
            int x=q.top();
            q.pop();
            --x;
            q.push(x);
            k--;
        }
        int ans=0;
        while(!q.empty()){
            // cout<<q.top()<<" ";
            ans += q.top()*q.top();
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends