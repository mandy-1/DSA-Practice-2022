//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
     
        // get the length of the mask
        int maskLength = (1ll<<(r-l+1)) - 1;
     
        // Shift the mask to the required position
        // "&" with y to get the set bits at between
        // l ad r in y
        int mask = ((maskLength)<<(l-1)) & y ;
        x = x | mask;
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends