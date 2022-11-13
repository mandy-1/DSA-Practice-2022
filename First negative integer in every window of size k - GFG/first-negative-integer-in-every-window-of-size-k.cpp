//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int N, long long int k) {
    queue<pair<long long int,int>>q;
    vector<long long int>ans;
    for(int i=0;i<min(k,N);i++){
        if(a[i]<0){
            q.push({a[i],i});
        }
    }
    int i=0,j=min(k-1,N-1);
    while(j<N){
        if(!q.empty()){
            if(q.front().second < i){
                while(!q.empty() && q.front().second<i){
                    q.pop();
                }                
            }
            if(q.front().second >=i){
                ans.push_back(q.front().first);
                if(q.front().second==i) q.pop();
            }
        }
        else{
            ans.push_back(0);
        }
        i++,j++;
        if(j<N){
            if(a[j]<0){
                q.push({a[j],j});
            }
        }
    }
    return ans;
 }