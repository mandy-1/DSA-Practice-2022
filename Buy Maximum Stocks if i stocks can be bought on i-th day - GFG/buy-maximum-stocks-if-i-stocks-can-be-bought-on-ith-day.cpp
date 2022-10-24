//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
// static bool comp(pair<int,int>a,pair<int,int>b){
//     return a.first
// }

    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({price[i],i+1});
        }
        int count=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i].first <= k){
                int curr=min(v[i].second,k/v[i].first);
                count +=curr;
                k -= curr*v[i].first;
            }
            if(k==0) break;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends