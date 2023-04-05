//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) 
    {
        unordered_map<int, int> mp; 
        for(auto it : arr) 
            mp[it]++;
        
        sort(arr.begin(), arr.end()); 
    
        int cntSpecialNum = 0; 
        for(int i = 0; i < n; i++)
        {
             if(mp[arr[i]] >= 2) 
            {
                cntSpecialNum++;
                continue; 
            }
            
            for(int j = 0; arr[j] < arr[i]; j++) 
            {
                if(arr[i] % arr[j] == 0)
                {
                    cntSpecialNum++; 
                    break;
                }    
            }
        }
        return cntSpecialNum;  
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends