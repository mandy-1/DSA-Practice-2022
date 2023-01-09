//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)return image;
        int n1=image.size();
        int n2=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int incol=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            auto temp=q.front();
            int x=temp.first;
            int y=temp.second;
            q.pop();
            for(int i=0;i<4;i++){
                if(x+dir[i][0]>=0 && x+dir[i][0]<n1 && y+dir[i][1]>=0 && y+dir[i][1]<n2 && incol==image[x+dir[i][0]][y+dir[i][1]]){
                   image[x+dir[i][0]][y+dir[i][1]]=color;
                    q.push({x+dir[i][0],y+dir[i][1]});
                }
            }
            // image[x][y]=color;
        }
        return image; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends