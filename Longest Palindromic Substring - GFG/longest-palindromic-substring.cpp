//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int i=0;
        int ans=1;
        pair<int,int>final;
        while(i<s.length()){
            int j=i+1,temp=i;
            
            if(j<s.length() && s[j]==s[i]){
                while(i>=0 && j<s.length() && s[i]==s[j]){
                    i--;
                    j++;
                }
                // ans=max(ans,j-i-1);
                if(ans<j-i-1){
                    ans = j-i-1;
                    final.first=i;
                    final.second=j;
                }
            }
            i=temp+1;
        }
        
        i=0;
        while(i<s.length()){
            int p=i-1,k=i+1;
            if(p>=0 && k<s.length() && s[p]==s[k]){
                while(p>=0 && k<s.length() && s[p]==s[k]){
                    p--;
                    k++;
                }
                // ans=max(ans,k-p-1);
                if(ans<k-p-1){
                    ans = k-p-1;
                    final.first=p;
                    final.second=k;
                }                
            }
            i++;
        }
        
        if(ans==1)return s.substr(0,ans);
        return s.substr(final.first+1,ans);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends