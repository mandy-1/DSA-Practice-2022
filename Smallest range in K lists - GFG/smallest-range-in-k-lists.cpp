//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    // pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    // {   int mini=INT_MAX,maxi=INT_MIN,range=INT_MAX;
    //     pair<int,int>ans;
    //     priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
    //     for(int i=0;i<k;i++){
    //         pq.push({arr[i][0],{i,0}});
    //         maxi=max(maxi,arr[i][0]);
    //     }
    //     while(!pq.empty()){
    //         auto num = pq.top();
    //         mini=num.first;
    //         pq.pop();
    //         if(range>maxi-mini){
    //             // cout<<mini<<" "<<maxi<<endl;
    //             ans={mini,maxi};
    //             range=maxi-mini;
    //         }
    //         if(num.second.second+1 < k){
    //             maxi=max(maxi,arr[num.second.first][num.second.second+1]);
    //             pq.push({arr[num.second.first][num.second.second +1],{num.second.first,num.second.second+1}});
    //         }
    //         else break;
    //         // cout<<endl;
    //     }
    //     return ans;
    // }
        class Node{
        public:
        int data,row,col;
        Node(int a,int b,int c){
            data=a;
            row=b;
            col=c;
        }
    };
    class cmp{
        public:
        bool operator()(Node *a,Node *b){ 
        return a->data>b->data;
        }
    };
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<Node*,vector<Node*>,cmp>q;
        int start=INT_MAX,end=INT_MIN;
        for(int i=0;i<k;i++){
            q.push(new Node(arr[i][0],i,0));
            start=min(start,arr[i][0]);
            end=max(end,arr[i][0]);
        }
        int mini=start,maxi=end;
        while(!q.empty()){
            Node *top=q.top();
            q.pop();
            mini=top->data;
            int i=top->row;
            int j=top->col;
            if(maxi-mini<end-start){
                start=mini;
                end=maxi;
            }
            if(j+1<n) {
                q.push(new Node(arr[i][j+1],i,j+1));
                maxi=max(maxi,arr[i][j+1]);
            }else break;
        }
    return make_pair(start,end);    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends