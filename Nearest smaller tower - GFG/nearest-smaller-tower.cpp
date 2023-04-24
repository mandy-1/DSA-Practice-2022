//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n=arr.size();
        vector<int>pre(n,-1);
        vector<int>fo(n,-1);
        stack<pair<int,int>>st;
        st.push({arr[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {   
            int num=arr[i];
            while(!st.empty()&&st.top().first>=num)
            {
                st.pop();
            }
            if(!st.empty())
            {
                pre[i]=st.top().second;
            }
            st.push({num,i});
            
        }
        stack<pair<int,int>>st1;
        st1.push({arr[0],0});
          for(int i=1;i<n;i++)
        {   
            int num=arr[i];
            while(!st1.empty()&&st1.top().first>=num)
            {
                st1.pop();
            }
            if(!st1.empty())
            {
                fo[i]=st1.top().second;
            }
            st1.push({num,i});
            
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            int index1=fo[i];
            int index2=pre[i];
            if(index1==-1&&index2==-1)
            {
                continue;
            }
            int dis1=-1;
            int dis2=-1;
          if(index1!=-1)
          {
              dis1=i-index1;
          }
          if(index2!=-1)
          {
              dis2=index2-i;
          }
          if(dis1==-1)
          {
              ans[i]=index2;
          }
          else if(dis2==-1)
          {
              ans[i]=index1;
          }
          else if(dis1==dis2)
          {
              if(arr[index1]!=arr[index2])
              {
                  if(arr[index1]>arr[index2])
                  {
                      ans[i]=index2;
                  }
                  else
                  {
                      ans[i]=index1;
                  }
              }
              else
              {
                  ans[i]=min(index1,index2);
              }
          }
        else{
            if(dis1>dis2)
            {
                ans[i]=index2;
            }
            else
            {
                ans[i]=index1;
            }
        }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends