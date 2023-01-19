//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
        int inf=100000000;
        vector<int>dis(n,inf);
        dis[0]=0;
        n--;
        while(n--){
            for(auto i:edges){
                if(dis[i[0]] !=inf){
                    int curr=dis[i[0]]+i[2];
                    
                    if(curr<dis[i[1]]){
                        dis[i[1]]=curr;
                    }
                }
            }
        }
        bool flag=false;
            for(auto i:edges){
                if(dis[i[0]] !=inf){
                    int curr=dis[i[0]]+i[2];
                    
                    if(curr<dis[i[1]]){
                        dis[i[1]]=curr;
                        flag=true;
                        break;
                    }
                }
            }  
            if(flag)return 1;
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends