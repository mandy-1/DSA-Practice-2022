//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
 int lenOfLongSubarr(int A[],  int N, int K) 
    { 
      int prefix_sum=0;

       int len=0;

       unordered_map<int,int>mp;

       for(int i=0;i<N;i++){

           prefix_sum+=A[i];

           if(prefix_sum==K)

                len=i+1;

           else if(mp.find(prefix_sum-K)!=mp.end()){

               len=max(len,i-mp[prefix_sum-K]);

           }   

           if(mp.find(prefix_sum)==mp.end()){

               mp[prefix_sum]=i;

           }

       }

       return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends