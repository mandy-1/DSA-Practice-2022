//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int answer = 0;
        int i = 0;
        int j = 0;
        int hzc=1;
        int vc = 1;
        while(i<M-1 && j< N-1){
            if(X[i]>Y[j]){
                answer += X[i]*vc;
                i++;
                hzc++;
            }
            else{
                answer+= Y[j]*hzc;
                vc++;
                j++;
            }
        }
        while(i<M-1){
            answer+=X[i]*vc;
            i++;
            hzc++;
            
        }
         while(j<N-1){
            answer+=Y[j]*hzc;
            j++;
            vc++;
            
        }
        return answer;
        
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends