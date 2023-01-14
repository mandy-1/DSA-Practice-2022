//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      vector<int> ans;
      vector<pair<int,int>> temp;
      for(int i=0;i<N;i++)
      {  
          temp.push_back({A[i],i});
      }
      sort(temp.begin(),temp.end());
      vector<long long int> pref(N);

      pref[0]=temp[0].first;

      for(int i=1;i<N;i++){ pref[i]=pref[i-1]+temp[i].first; }

      for(auto x: Queries)
      {  
          int cost=x[0];
          int k=x[1];
          if(cost<temp[0].first){ ans.push_back(0);continue;  }
          int ind=lower_bound(pref.begin(),pref.end(),cost)-pref.begin();
          int toys=0;
          if(ind<N and pref[ind]==cost){ cost=0,toys=ind+1;  } 

          else { toys=ind;cost=(cost-pref[ind-1]);ind--; }

           unordered_set<int> set;

            for(int i=2;i<2+k;i++)
          {  
               auto cur=x[i]-1;
               if(A[cur]<temp[ind].first)
               {  
                   cost+=A[cur];toys--;
               }

               else if(A[cur]==temp[ind].first and cur<=temp[ind].second)
               {  
                    cost+=A[cur];toys--;
               }
               set.insert(cur);

          }
          ind++;

          while(ind<N and cost>=temp[ind].first)

          {  

              if(set.find(temp[ind].second)==set.end())

              {  

                  cost-=temp[ind].first;toys++;

              }

              ind++;

          }

          if(toys>0){

          ans.push_back(toys); }

          else{ ans.push_back(0); }

      }

       return ans;

  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends