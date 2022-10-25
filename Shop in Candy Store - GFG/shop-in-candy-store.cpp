//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int i=0,j=N-1;
        int cur=0;
        int mini=0;
        int maxi=0;
        int temp=N-1;
        while(i<=j && cur<N){
            mini += candies[i];
            maxi += candies[temp];
            cur +=1+K;
            i++,j-=K;
            temp--;
        }
        // cur=0;
        // i=N-1;
        // J=0;
        // int maxi;
        // while(i>j && cur<N){
        //     mini += candies[i];
        //     cur +=1+K;
        //     i++,j-=K;
        // }
        return {mini,maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends