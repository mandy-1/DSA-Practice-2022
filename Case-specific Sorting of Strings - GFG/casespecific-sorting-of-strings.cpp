//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<int> s;
        vector<int> c;
        vector<int> sl;
        vector<int> cl;
       
        for(int i=0;i<n;i++){
            if(isupper(str[i])){
                c.push_back(i);
                cl.push_back(str[i]);
               
            }if(islower(str[i])){
                s.push_back(i);
                sl.push_back(str[i]);
               
            }
        }
         sort(cl.begin(), cl.end());
          sort(sl.begin(), sl.end());
          
          for(int i=0;i<sl.size();i++){
              str[s[i]]=sl[i];
              
          }
          for(int i=0;i<cl.size();i++){
              str[c[i]]=cl[i];
              
          }
          return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends