//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{   long long mod=1e9+7;
    long long cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+2<n){
                if(j-1>=0)cnt++;
                if(j+1<m)cnt++;
            }
            if(i-2>=0){
                if(j-1>=0)cnt++;
                if(j+1<m)cnt++;
            }
            if(j+2<m){
                if(i-1>=0)cnt++;
                if(i+1<n)cnt++;
            }
            if(j-2>=0){
                if(i-1>=0)cnt++;
                if(i+1<n)cnt++;
            }
            cnt%=mod;
        }
    }
    long long tol=(((n*m)%mod)*((n*m)-1)%mod)%mod;
    // cout<<tol<<" "<<cnt<<endl;
    return tol-cnt;
}