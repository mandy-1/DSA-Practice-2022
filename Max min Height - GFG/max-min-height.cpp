//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
        bool pos(long long mid,long long k,int w,vector<int>&a){
            queue<pair<int,long long>>q;
            long long curr=0;
            long long extra=0;
            for(int i=0;i<a.size();i++){
                if(q.size()&&q.front().first==i){
                    curr-=q.front().second;
                    q.pop();
                }
                if(a[i]+curr>=mid)continue;
                else {
                    q.push({i+w,mid-a[i]-curr});
                    extra+=mid-a[i]-curr;
                    curr+=mid-a[i]-curr;
                }
            }
            return extra<=k;
        }

        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            long long low=0,high=INT_MAX*1ll*100000;
            while(low<high){
                long long mid=(low+high)/2;
                if(mid==low)break;
                if(pos(mid,k,w,a))low=mid;
                else high=mid;
            }
            if(pos(high,k,w,a))return high;
            return low;
        }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends