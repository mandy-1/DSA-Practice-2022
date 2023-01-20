//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int t[1005][1005] ;
	int Solve(int *A, int i, int N, int K)
	{
	    if(K==0) return 0 ;
	    
	    if(i==N) return 1e9;
	    
	    if(t[i][K]!=-1)
	    return t[i][K] ;
	    
	    int Ans = 1e9 ;
	    
	    for(int j=i+1; j<N ; j++)
	    {
	        if(A[j] >= A[i]){
	            Ans = min(Ans, A[j] + Solve(A,j,N,K-1)) ;
	        }
	    }
	    
	    return t[i][K] = Ans ;
	}

	int minSum(int arr[], int N, int K) 
	{ 
		memset(t,-1,sizeof(t)) ;
        int Ans = 1e9 ;
        for(int i=0 ; i<=N-K; i++)
        {
            Ans = min(Ans, arr[i] + Solve(arr,i,N,K-1)); 
        }
		if(Ans >= 1e9) return -1;
		return Ans ;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

        

	    Solution ob;
	    cout << ob.minSum(a, n, k) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends