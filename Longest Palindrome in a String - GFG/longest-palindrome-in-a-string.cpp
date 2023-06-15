//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n=s.size();
        int dp[n][n];
        int max_pal_length=0,start=-1,end=-1;
        
        //step 1 and the most important step --> diagonal filling of the dp
        for(int col=0;col<n;col++)
        {
            int i=0,j=col;
            while(i<n and j<n)
            {
                if(i==j)   //case 1 -->single size substring = palindrome
                    dp[i][j]=1;
                
                else if(j-i==1)   //case 2 ---> 2 element substring  
                  dp[i][j]=(s[i]==s[j])?1:0;          
                
                //case 3 kitne b elemnt ki substring hai
                //[1,5] substring hai uske liye check [2,4]
                else    
                   dp[i][j]=(dp[i+1][j-1]==1 and s[i]==s[j])?1:0;
        
                
                if(dp[i][j]==1 and j-i+1>max_pal_length)
                {
                    max_pal_length=j-i+1;
                    start=i;
                }
                
                i++; j++;
            }
        }
        return s.substr(start,max_pal_length);  //return longest palindromic substring       
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends