//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int i=0,j=0,cur=1,ans=0;
        while(j<a.size()){
            cur *= a[j];
            if(cur<k){
                // cout<<i<<" "<<j<<"   ";
                ans += (j-i)+1;
            }
            else{
                while(i<=j && cur>=k){
                    cur /= a[i];
                    i++;
                }
                if(cur != 1 && i<n){
                    // cout<<i<<" "<<j;
                    ans += (j-i)+1;   
                }
            }
            // cout<<endl;
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends