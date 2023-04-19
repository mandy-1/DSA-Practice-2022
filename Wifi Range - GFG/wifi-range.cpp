//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int f,k,j;
        for(int i=0;i<N;i++)
        {
            if((i-X)<0)
                k=0;
            else
                k=i-X;
            if((i+X)>N)
                f=N;
            else
                f=i+X;
            if(S[i]=='0')
            {
                for(j=k;j<=f;j++)
                {
                    if(S[j]=='1')
                    {
                    break;}
                }
                if(j==f+1)
                {return 0;}
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends