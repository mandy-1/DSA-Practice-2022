//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> mt, int R, int C){
        int i=0,j=0;
        int up=0,right=1,down=0,left=0;
        while(true){
            if(mt[i][j]==0){
                if(right){
                    j++;
                }
                else if(down){
                    i++;
                }
                else if(left){
                    j--;
                }
                else if(up){
                    i--;
                }
            }
            else {
                mt[i][j]=0;
                if(right){
                    right=0;
                    down=1;
                    i++;
                }
                else if(down){
                    down=0;
                    left=1;
                    j--;
                }
                else if(left){
                    up=1;
                    left=0;
                    i--;
                }
                else if(up){
                    right=1;
                    up=0;
                    j++;
                } 
            }
            if(i<0) return {i+1,j};
            if(j<0) return {i,j+1};
            if(i>=R) return {i-1,j};
            if(j>=C) return {i,j-1};
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends