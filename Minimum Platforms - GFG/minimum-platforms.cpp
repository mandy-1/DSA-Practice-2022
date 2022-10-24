//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    
    int findPlatform(int arr[], int dep[], int n)
    
    {   vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({dep[i],arr[i]});  
        }
        sort(v.begin(),v.end(),comp);
        vector<int>plt;
        plt.push_back(v[0].first);
        int cnt=1;
        for(int i=1;i<n;i++){
            int j=0;
            for(;j<cnt;j++){
               if(plt[j]<v[i].second){
                   plt[j]=v[i].first;
                   break;
               }
            }
            if(j==cnt){
              plt.push_back(v[i].first);
              cnt++;  
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<plt[i]<<" ";
        // }
        // cout<<endl;
        return plt.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends