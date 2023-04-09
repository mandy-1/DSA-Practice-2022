//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define mod 1000000007
class Solution {
    bool check(int n , int c , int d){
        while(n){
            int r = n % 10;
            n /= 10;
            if(r != c && r != d)
            return false;
        }
        return true;
    }
    long long binpower(long long a , long long n){
        long long res = 1;
        while(n){
            if(n % 2)
            res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }
  public:
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        long long res = 0;
        long long fact[N + 1];
        fact[0] = 1;
        for(int i = 1 ; i <= N ; i++)
        fact[i] = (fact[i - 1] * 1LL * i) % mod;
        for(int i = 0 ; i <= N ; i++){
            int cnta = i , cntb = N - i;
            if(check(cnta * A + cntb * B , C , D)){
                res += (fact[N] * binpower((fact[i] * fact[N - i]) % mod , mod - 2)) % mod;
                res %= mod;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends