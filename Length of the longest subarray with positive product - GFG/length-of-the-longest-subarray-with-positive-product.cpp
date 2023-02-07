//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           int ans=0,maxi=-1,mini=-1,negcnt=0,srt=0;
           long long prd =1;
           for(int i=0;i<arr.size();i++){
               prd = (prd * arr[i])%1000000007;
               if(arr[i]<0)negcnt++;
               if(prd<0){
                   if(mini == -1){
                       mini = i;
                   }
                   else{
                       ans= max(ans,i-mini);
                   }
               }
               else if(prd>0){
                   if(negcnt !=0 && negcnt%2==0){
                       ans = max(ans,i-srt+1);
                   }
                   if(maxi == -1){
                       ans= max(ans,1);
                       maxi=i;
                   }
                   else{
                       ans= max(ans,i-maxi+1);
                   }
               }
               else{
                   maxi=-1;
                   mini=-1;
                   prd=1;
                   srt=i+1;
                   negcnt=0;
               }
            //   cout<<mini<<" "<<maxi<<" "<<ans<<endl;
           }
        //   cout<<srt;
           return ans;
        }
        // 3
        // -1 5 8
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends