//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    int sol2(string& s){
        int ans=INT_MIN;
        int cur=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                cur--;
            }
            else cur++;
            ans=max(cur,ans);
            if(cur<0)cur=0;
        }
        return ans;
    }    
	int maxSubstring(string S)
	{   
	    int n2=sol2(S);
	    return n2;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends