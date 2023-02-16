//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int goodStones(int n,vector<int> &arr){

       vector<int>adj[n];

       vector<int>indegree(n,0);

    //   forming the adjacency list

       for(int i=0;i<n;i++)

       {

           int u=i+arr[i];

           if(u<0 ||u>n-1)

           continue;

           adj[u].push_back(i);

        //   find the indegree of each node.

           indegree[i]++;

       }

     
       queue<int> q;

       for(int i=0;i<n;i++)

       {

           if(indegree[i]==0)q.push(i);

       }

    //   traversing each node 

       while(!q.empty())

       {

           int node=q.front();

           q.pop();

          for(auto it: adj[node]){

                indegree[it]--;

                if(indegree[it]==0){

                    q.push(it);

                }

            }

        }

        // for checking the cycle we have to check if all node is traversed or not 

        // but here we have to check all node  which  are traversed and indegree is 0;

        int cnt = 0;

        for(int i = 0; i<n; i++){

            if(indegree[i]==0){

                cnt++;

            }

        }

        return cnt;

    } 
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends