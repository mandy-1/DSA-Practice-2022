//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        map<int,int>mp;
        for(auto i:hand){
            mp[i]++;
        }
        while(!mp.empty()){
            int cnt=1;
            int num=mp.begin()->first;
            mp[num]--;
            if(mp[num]==0) mp.erase(num);
            // cout<<num<<endl;
            num++;
            while(cnt<groupSize){
                if(!mp[num]){
                    // cout<<num<<" ";
                    return false;
                }
                else{
                    mp[num]--;
                    cnt++;
                    if(mp[num]==0){
                        mp.erase(num);
                    }
                    num++;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends