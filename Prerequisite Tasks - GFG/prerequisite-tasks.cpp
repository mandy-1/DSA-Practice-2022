//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& arr) {
	    vector<vector<int>>edg(N);
	    vector<int>order(N,0);
	    for(int i=0;i<arr.size();i++){
	        edg[arr[i].first].push_back(arr[i].second);
	        order[arr[i].second]++;
	    }
	    queue<int>q;
	    int cnt=0;
	    for(int i=0;i<N;i++){
	        if(order[i]==0){
	            q.push(i);
	            cnt++;
	        }
	    }
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();
	        for(int i=0;i<edg[temp].size();i++){
	            if(--order[edg[temp][i]]==0){
	                cnt++;
	                q.push(edg[temp][i]);
	            }
	        }
	    }
	    return N==cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends