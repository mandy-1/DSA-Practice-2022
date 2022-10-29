//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      bool isSafe(int row,int col,vector<vector<int>>board,int n)

    {

        //check left

        int x=row;

        int y=col;

        while(y>=0)

        {

            if(board[x][y]==0)

            {

                return false;

            }

            y--;

        }

        

        x=row;

        y=col;

        while(x>=0 && y>=0)

        {

            if(board[x][y]==0) return false;

            x--;

            y--;

        }

        

        x=row;

        y=col;

        

        while(x<n && y>=0)

        {

            if(board[x][y]==0) return false;

            x++;

            y--;

        }

        

        return true;

    }

    void solve(vector<vector<int>>&res,vector<vector<int>>&board,int col,int n,vector<int>temp)

    {

        if(col==n)

        {

            res.push_back(temp);

            return;

        }

        

        for(int row=0;row<n;row++)

        {

            if(isSafe(row,col,board,n))

            {

                temp.push_back(row+1);

                board[row][col]=0;

                solve(res,board,col+1,n,temp);

                temp.pop_back();

                board[row][col]=-1;

            }

        }

        

    }

    vector<vector<int>> nQueen(int n) 

    {

        int col=0;

        vector<vector<int>>board(n,vector<int>(n,-1));

        vector<int>temp;

        vector<vector<int>>res;

        solve(res,board,col,n,temp);

        return res;

        

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends