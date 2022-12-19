//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int,vector<int>,greater<int>>mini;
    priority_queue<int>maxi;
    void insertHeap(int &x)
    {
        if(maxi.empty() || x<maxi.top())maxi.push(x);
        else mini.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxi.size()>mini.size()+1){
            mini.push(maxi.top());
            maxi.pop();
        }
        if(maxi.size()<mini.size()){
            maxi.push(mini.top());
            mini.pop();
        }        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if((mini.size()+maxi.size())%2!=0)return float(maxi.top());
        return (float(mini.top())+float(maxi.top()))/2;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends