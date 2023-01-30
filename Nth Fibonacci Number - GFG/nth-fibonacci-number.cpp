//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1000000007;
    // long long int sol(int n){
    //     if(n==1)return 1;
    //     if(n==0)return 0;
    //     return sol(n-1)%mod +sol(n-2)%mod;
    // }
  
    long long int nthFibonacci(long long int n){
        if(n==1)return 1;
        if(n==0)return 0;
        long long int num=2;
        long long int temp1=0,temp2=1;
        while(num <= n){
            long long int dum=(temp1%mod +temp2%mod)%mod;
            temp1=temp2;
            temp2=dum;
            num++;
        }
        return temp2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends