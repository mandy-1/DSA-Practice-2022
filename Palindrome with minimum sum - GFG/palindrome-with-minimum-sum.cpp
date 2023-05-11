//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int ans=0;
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i] == '?' && s[j]!='?'){
                s[i]=s[j];
            }
            else if(s[i]!='?' && s[j] == '?'){
                s[j]=s[i];
            }
            else if(s[i] != s[j]){
                return -1;
            }
            i++;
            j--;
        }
        int cnt=0;
        string temp="";
        for(auto i:s){
            if(i != '?'){
                temp += i;
            }
        }
        for(int i=1;i<temp.length();i++){
            cnt += abs(temp[i]-temp[i-1]); 
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends