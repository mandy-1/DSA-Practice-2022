//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
string reverseEqn (string s)
        {
            stack<char> s2;
            stack<string> s1;
            for(int i=0;i<s.size();i++)
            {
                if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
                {
                    s2.push(s[i]);
                }
                else
                {
                    string str = "";
                    while((s[i] >= '0' and s[i] <= '9') and i < s.size())
                    {       
                        str += s[i];
                        i++;
                    }
                    i--;
                    s1.push(str);
                }
            }
            string ans = "";
            ans += (s1.top());
            s1.pop();
            while(!s1.empty() and !s2.empty())
            {
                ans += (s2.top());
                ans += (s1.top());
                s1.pop();
                s2.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends