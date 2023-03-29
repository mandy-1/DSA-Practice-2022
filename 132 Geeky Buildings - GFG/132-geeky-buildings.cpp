//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int nums[], int n){
		vector<int>mini(n);
		mini[0]=0;
		int cur=0;
		stack<int>st;
		st.push(0);
		for(int i=1;i<n;i++){
		    while(!st.empty() && nums[st.top()] < nums[i]){
		        st.pop();
		    }
		    if(nums[i] < nums[cur]){
		        mini[i] = i;
		        cur=i;
		    }
		    else{
		        mini[i]=cur;
		    }
		    if(!st.empty()){
		        if(nums[mini[st.top()]] < nums[i]){
		            return true;
		        }
		    }
		    st.push(i);
		}
		return false;
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
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends