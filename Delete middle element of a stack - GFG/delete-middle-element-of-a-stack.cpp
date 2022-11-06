//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void sol(stack<int>&s,int cnt,int& n){
        if((n%2==0 && cnt==0)|| (n%2 !=0 && cnt==1)){
            s.pop();
            return;           
        }
        int temp=s.top();
        s.pop();
        sol(s,cnt-1,n);
        s.push(temp);
    }
    
    void deleteMid(stack<int>&s, int n)
    {   
        if(n==1)s.pop();
        int cnt=n/2;
        if(n%2!=0)cnt++;
        sol(s,cnt,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends