//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void solve(string s, vector<string> &dict, vector<string> &ans, string osf){
        
        if(s.size() == 0){
            osf.pop_back();
            ans.push_back(osf);
            return;
        }
        
        for(int i=1; i<=s.size(); i++){
            
            string left = s.substr(0, i);
            string right = s.substr(i);
            
            auto it = find(dict.begin(), dict.end(), left);
            if(it != dict.end()){
                solve(right, dict, ans, osf + left + " ");
            }
            
        }
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        solve(s, dict, ans, "");
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends