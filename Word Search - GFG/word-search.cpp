//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool dfs(int r, int c, vector<vector<char>> &board, string word, int n, int m, int ind, vector<vector<int>> &vis) {
        if(board[r][c] != word[ind])
            return false;
            
        if(ind == word.size() - 1) 
            return true;
            
        vis[r][c] = 1;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++) {
            int nx = r + dx[i], ny = c + dy[i];
            if(nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny]) {
                if(dfs(nx, ny, board, word, n, m, ind + 1, vis))
                    return true;
            }
        }
        
        vis[r][c] = 0;
        return false;
    }

    bool isWordExist(vector<vector<char>> &board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0] and !vis[i][j]) {
                    if(dfs(i, j, board, word, n, m, 0, vis))
                        return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends