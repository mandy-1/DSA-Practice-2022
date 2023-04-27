//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   char solve(int freq[], int k) {
        int count = 0; 
        for(int i = 25; i >= 0; i--) {
            count += freq[i];  
            if(count >= k) 
                return i + 'a';
        }
        return '.';
    }
    vector<char> easyTask(int n,string str,int q,
    vector<vector<string>> &queries){
        vector<char> ans; 
        int len = queries.size();
        for(int i = 0; i < len; i++) {
            int qNo = stoi(queries[i][0]); 
            
            if(qNo == 1) {
                int ind = stoi(queries[i][1]);
                char ch = queries[i][2][0]; 
                str[ind] = ch;
            } else {
                int left = stoi(queries[i][1]); 
                int right = stoi(queries[i][2]); 
                int k = stoi(queries[i][3]); 
                int freq[26] = {0}; 
                
                for(int j = left; j <= right; j++) {
                    int ele = str[j] - 'a'; 
                    freq[ele]++; 
                }
                
                char ch = solve(freq, k); 
                ans.push_back(ch);
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends