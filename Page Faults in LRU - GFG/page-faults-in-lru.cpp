//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  int pageFaults(int n, int c, int pages[]){
        // code here
        int iter = 0;   //variable, to keep a track of order
        map<int, int>order;
        unordered_map<int, int>page;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(page.find(pages[i]) == page.end()){  //not present in cache
                if(page.size() < c){ //cache is full
                    page[pages[i]] = iter;
                    order[iter] = pages[i];
                }
                else{ //cache is not full
                    auto it = order.begin();
                    page.erase(it->second);
                    order.erase(it);
                    order[iter] = pages[i];
                    page[pages[i]] = iter;
                }
                ans++;  //as not present in cache, increase page fault
            }
            else{	//already present in cache, just update the iter
                int old = page[pages[i]];
                order.erase(old);
                page[pages[i]] = iter;
                order[iter] = pages[i];
            }
            iter++; 
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends