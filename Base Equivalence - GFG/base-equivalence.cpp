//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        string yes = "Yes", no = "No";
        int ans = -1;
        int low = 2, high = 32;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            int dig = log2(n)/log2(mid) + 1;
            if(dig == m) {
                return yes;
            }
            else if(dig < m) high = mid-1;
            else low = mid+1;
        }
        return no;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends