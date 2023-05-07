//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        string ans="";
        ans += str[0];
        int i=1;
        while(i<str.length() && (str[i]<str[i-1] || (str[i]==str[i-1] && i>1))){
            ans+=str[i];
            i++;
        }
        string temp=ans;
        reverse(ans.begin(),ans.end());
        return temp+ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends