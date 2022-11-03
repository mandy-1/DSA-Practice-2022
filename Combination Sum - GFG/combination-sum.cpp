//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>>ans;
    void sol(int idx,vector<int>&a,int& tar,vector<int>&cur){
        if(tar<0)return ;
        if(tar==0){
            ans.push_back(cur);
            return;
        }
            for(int i=idx;i<a.size();i++){
                tar-=a[i];
                cur.push_back(a[i]);
                sol(i,a,tar,cur);
                tar+=a[i];
                cur.pop_back();
            }        
    }
    static bool comp(vector<int>a,vector<int>b){
        // if(a.size()==b.size())
        return a.size()>b.size();
    } 
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>cur;
        // sol(0,A,B,cur);
        // for(int i=0;i<ans.size();i++){
        //     sort(ans[i].begin(),ans[i].end());
        // }
        // sort(ans.begin(),ans.end(),comp);
         // Your code here

        sort(A.begin(), A.end());

        A.erase(unique(A.begin(), A.end()), A.end()); //remove duplicates
        sol(0,A,B,cur);
        
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends