//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        if(a == b)
            return 0;
        int abits = 0;
        int bbits = 0;
        for(int i = 31 ; i >= 0 ; i--)
        {
            int abit = (a >> i)&1;
            int bbit = (b >> i)&1;
            if(abit == bbit)
                continue;
            else if(abit == 1)
                abits++;
            else
                bbits++;
        }
        if(abits == 0 || bbits == 0)
            return 1;
        return 2;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends