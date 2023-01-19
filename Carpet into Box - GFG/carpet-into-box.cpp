//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int count = 0;
        int mx1 = max(A, B);
        int mx2 = max(C, D);
        int min1 = min(A, B);
        int min2 = min(C, D);
        if(mx1<=mx2 && min1<=min2){
            return 0;
        }
        if(mx1 <= mx2){
            while(min1>min2){
                min1 = floor(min1/2);
                count++;
            }
        }
        else if(min1<=min2){
            while(mx1>mx2){
                mx1 = floor(mx1/2);
                count++;
            }
        }
        else{
            while(mx1>mx2){
                mx1 = floor(mx1/2);
                int tmx = max(mx1, min1);
                int tmin = min(mx1, min1);
                mx1 = tmx;
                min1 = tmin;
                count++;
            }
            while(min1>min2){
                min1 = floor(min1/2);
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends