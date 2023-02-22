//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        int take = -prices[idx] + dp[idx+1][0][cap];
                        int notTake = 0 + dp[idx+1][1][cap];
                        dp[idx][buy][cap] = max(take,notTake);
                    }
                    else{
                        int sell = prices[idx] + dp[idx+1][1][cap-1];
                        int notSell = 0 + dp[idx+1][0][cap];
                        dp[idx][buy][cap] = max(sell,notSell);
                    }
                }
            }
        }
        
        return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends