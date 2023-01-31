//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

struct cmp {
    bool operator() (pair<int,int> a,pair<int,int> b) const {
        if(a.first==b.first){
            if(a.first<0 and b.first<0)return a.second<b.second;
            else return a.second>b.second;
        }
        else return a.first<b.first;
    }
};
class Solution{
public:
    vector<vector<int>> minCashFlow(vector<vector<int>> &t, int n)
    {
        set<pair<int,int>,cmp>s;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i]-=t[i][j];
                arr[j]+=t[i][j];
            }
        }
        for(int i=0;i<n;i++){
            s.insert({arr[i],i});
        }
        vector<vector<int>>ans(n,vector<int>(n,0));
        while(s.size()>1){
            auto f=s.begin();
            auto l=s.end();
            l--;
            int mini=min(abs(f->first),l->first);
            ans[f->second][l->second]=mini;
            if(mini==abs(f->first)){
                if(l->first-mini>0)s.insert({l->first-mini,l->second});
            }
            else s.insert({mini+f->first,f->second});
            s.erase(f);
            s.erase(l);
        }
        return ans;
    }
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
        vector<vector<int>> g(n,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>g[i][j];
        }
        Solution s;
        vector<vector<int>> r=s.minCashFlow(g,n);
        for(auto j:r)
        {
            for(auto i:j)
                cout<<i<<" ";
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}
// } Driver Code Ends