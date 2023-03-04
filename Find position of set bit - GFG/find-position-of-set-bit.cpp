//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPowerofTwo(int n){
        
        if (n <= 0) return false; 
        return !(n & (n - 1));  
        
    }
    int findPosition(int n) {
        if(!isPowerofTwo(n))return -1;
        int x=0;
        while(1<<x <= n) x++;
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends