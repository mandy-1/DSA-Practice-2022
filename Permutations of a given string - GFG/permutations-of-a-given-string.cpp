//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
  void solve(vector<string> &res, string &str,int idx){
            if(idx==str.size()-1){
            res.push_back(str);
            return;
            }
            for(int i=idx;i<str.length();i++){
                swap(str[idx],str[i]);
                solve(res,str,idx+1);
                swap(str[idx],str[i]);
            }
        }
        vector<string>find_permutation(string S)
        {
          
            vector<string>res;
            solve(res,S,0);
             unordered_set<string> st;
            for(auto i:res)
            {
                st.insert(i);
            }
            res.clear();
            for(auto i:st)
            {
                res.push_back(i);
            }
         
            sort(res.begin(),res.end());
            return res;
        }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends