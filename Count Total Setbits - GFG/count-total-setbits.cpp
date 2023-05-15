//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        long long ans = 0;
        int num = 1;
        int num2 = 2;
        
        for(int i = 0; i < 31; i++){
            ans += (N / num2) * num;
            int rem = (N % num2) - num + 1;
            if(rem > 0)
                ans += rem;
                
            num <<= 1;
            num2 <<= 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends