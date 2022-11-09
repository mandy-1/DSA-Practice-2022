//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
                stack<char> st;
        char o;
        for(char c:s){
            if(c==')' || c=='}' || c==']'){
                if(c==')') o='(';
                else if(c==']') o='[';
                else o='{';
                bool f=0;
                while(!st.empty() && st.top()!=o){
                    if(st.top()=='+'||st.top()=='-'||st.top()=='*' || st.top()=='/') f=1;
                    st.pop();
                }
                if(f==0 || f==1 && st.empty()) return 1;
                st.pop();
            }
            else st.push(c);
        }
        return !st.empty();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends