//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int addMinChar(string str){
        string temp = str;
        reverse(str.begin(),str.end());
        
        string s = temp+"$"+str; 
        vector<int>arr(s.length(),0);
        for(int i=1;i<s.length();i++){
            int j=arr[i-1];
            while(j>0 && s[i] != s[j]){
                j--;
            }
            if(s[i]==s[j]){
                j++;
            }
            arr[i]=j;
        }
        // cout<<arr[s.length()-1]<<" ";
        return str.length() - arr[s.length()-1]; 
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends