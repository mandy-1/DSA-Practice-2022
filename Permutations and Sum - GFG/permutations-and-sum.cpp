//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
void help(string s , set<string> &s1 , int i)
 {
     if(i == s.length())
     {
         return ;
     }

     s1.insert(s);

     for(int ind = i; ind < s.length(); ind ++)
     {

         swap(s[ind] , s[i]);

         help(s , s1 , i + 1);

     }

 }

 vector<int> permutaion(int N) {

     string s = to_string(N);

     set<string> s1;

     help(s , s1 , 0);

     int sum = 0;

     for(auto x : s1)
     {
         sum += atoi(x.c_str());
     }

     return {s1.size() , sum};

 }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.permutaion(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends