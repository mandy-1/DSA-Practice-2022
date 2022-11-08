//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insert_at_bottom(stack<int>& st, int x)
    {
     
        if (st.size() == 0) {
            st.push(x);
        }
        else {
     
            // All items are held in Function Call
            // Stack until we reach end of the stack
            // When the stack becomes empty, the
            // st.size() becomes 0, the above if
            // part is executed and the item is
            // inserted at the bottom
     
            int a = st.top();
            st.pop();
            insert_at_bottom(st, x);
     
            // push allthe items held in
            // Function Call Stack
            // once the item is inserted
            // at the bottom
            st.push(a);
        }
    }
     
    // Below is the function that
    // reverses the given stack using
    // insert_at_bottom()
    void Reverse(stack<int>& st)
    {
        if (st.size() > 0) {
     
            // Hold all items in Function
            // Call Stack until we
            // reach end of the stack
            int x = st.top();
            st.pop();
            Reverse(st);
     
            // Insert all the items held
            // in Function Call Stack
            // one by one from the bottom
            // to top. Every item is
            // inserted at the bottom
            insert_at_bottom(st, x);
        }
        return;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends