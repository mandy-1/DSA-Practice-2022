//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int>ans(n);
        if(n==0)return ans;
        stack<int>st;
        st.push(arr[n-1]);
        ans[n-1]=-1;
       for(int i=n-2;i>=0;i--){
           while(!st.empty() && st.top()>=arr[i])st.pop();
           if(st.empty())ans[i]=-1;
           else ans[i]=st.top();
           st.push(arr[i]);
       }
       return ans;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends